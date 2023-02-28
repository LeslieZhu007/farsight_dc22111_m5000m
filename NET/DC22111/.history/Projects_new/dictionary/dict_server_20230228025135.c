#include "dictionary.h"



int main(int argc, char const *argv[])
{
    //捕获17号信号，注册新的处理函数，用于回收僵尸进程
    __sighandler_t s = signal(SIGCHLD,handler);
    if (SIG_ERR == s)
    {
        printf("signal");
        return -1;
    }
    
    //1.socket  创建流式套接字  -->> TCP
    int sfd =  socket(AF_INET, SOCK_STREAM, 0);
    if (sfd < 0)
    {
        ERR_MSG("socket");
        return -1;
    }
    printf("sfd = %d\n",sfd);

    //允许端口快速被复用
    int reuse = 1;
    if(setsockopt(sfd,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(reuse)) < 0)
    {
        ERR_MSG("setsockopt");
        return -1;
    }

    //填充地址信息结构体，真实的地址信息结构体在man 7 ip
    //AF_INET --> man 7 ip
    struct sockaddr_in sin;
    sin.sin_family = AF_INET;   //必须要填AF_INET
    sin.sin_port = htons(PORT); //1024~49151 网络字节序
    sin.sin_addr.s_addr = inet_addr(IP);  //本机IP

    //2.bind: 功能 将IP地址和端口号绑定到指定套接字中
    if(bind(sfd, (const struct sockaddr *)&sin,sizeof(sin)) < 0)
    {
        ERR_MSG("bind");
        return -1;
    }
    printf("bind success __%d__\n",__LINE__);

    //3.listen: 将套接字设置为被动监听状态，只负责监听是否有客户端连接成功
    if(listen(sfd,10) <0)
    {
        ERR_MSG("listen");
        return -1;
    }
    printf("listen success __%d__\n",__LINE__);
    int login_fail_flag = 0; //登录失败状态标识 1:失败  0:成功

    //初始化数据库，导入数据
    //创建数据库
    sqlite3 *db = NULL;
    if(sqlite3_open(DB_NAME,&db)!= SQLITE_OK)
    {
        fprintf(stderr,"database create failed,__%d__,%d,%s\n",__LINE__,sqlite3_errcode(db),
        sqlite3_errmsg(db));
        return -1;
    }
    printf("database create success!\n");
    database_init(db);


    struct sockaddr_in cin; //存储客户端的地址信息
    socklen_t addrlen = sizeof(cin);
    int newfd = 0;
    int cpid = 0;
    while (1)
    {
        //父进程只负责连接
        newfd =  accept(sfd,(struct sockaddr *)&cin,&addrlen);
        if (newfd < 0)
        {
            ERR_MSG("accept");
            return -1;
        }
        printf("[%s | %d] newfd = %d\n",inet_ntoa(cin.sin_addr),ntohs(cin.sin_port),newfd);


        cpid = fork();
        if (0==cpid)
        {
            close(sfd);  //sfd对于子进程没有用
            //与客户端交互的代码

            deal_cli_inter(newfd,cin,db);

            //退出子进程
            exit(0);
        } else if(cpid > 0)
        {
            close(newfd);  //newfd对于父进程没有用
        }
    }

    close(sfd);
    return 0;
}

int deal_cli_inter(int newfd,struct sockaddr_in cin,sqlite3 *db)
{
    //通过文件描述符，读取数据
    //原型 ssize_t recv(int sockfd, void *buf, size_t len, int flags);
    msg_t msg;
    bzero(&msg,sizeof(msg));
    ssize_t  ret = 0;
    while (1)
    {
        
        ret = recv(newfd,&msg,sizeof(msg),0);
        if (ret < 0)
        {
            ERR_MSG("recv");
            break;
        } else if (0 == ret)
        {
            //当用户名存在的时候，将用户表status置0
            /*
                在一级菜单界面，按下退出，由于还未登录，所以不能将状态位置0
            */
            printf("[%s:%d] 断开连接\n",inet_ntoa(cin.sin_addr),ntohs(cin.sin_port));
            break;
        }
        printf("[%s:%d] 连接成功\n",inet_ntoa(cin.sin_addr),ntohs(cin.sin_port));
        /*******************************************************/
        switch (msg.type)
        {
            case 1:
                do_server_register(newfd, &msg, db);
                break;
            case 2:
                do_server_login(newfd, &msg, db);
                break;
            case 3:
                do_server_exit(newfd, &msg, db);
                break;
            case 4:
                do_server_word_query(newfd, &msg, db);
                break;
            case 5:
                do_server_history_query(newfd,&msg, db);
                break;
            
            default:
                break;
        }
    }
    close(newfd);
    return 0;
}







//数据库初始化，创建数据库及建表
void database_init(sqlite3 *db)
{
    //创建表
    //1.创建单词及释义表
    char *errmsg = NULL;
    if (sqlite3_exec(db,WORD_SQL,NULL,NULL,&errmsg)!= SQLITE_OK)
    {
        fprintf(stderr,"dictionary table create failed,__%d__,%d,%s\n",__LINE__,sqlite3_errcode(db),errmsg);
        return;
    }
    printf("dictionary table create success!\n");

    //2.创建历史记录表
    if (sqlite3_exec(db,HISTORY_SQL,NULL,NULL,&errmsg)!= SQLITE_OK)
    {
        fprintf(stderr,"history table create failed,__%d__,%d,%s\n",__LINE__,sqlite3_errcode(db),errmsg);
        return;
    }
    printf("history table create success!\n");

    //3.创建用户表
    if (sqlite3_exec(db,USER_SQL,NULL,NULL,&errmsg)!= SQLITE_OK)
    {
        fprintf(stderr,"user table create failed,__%d__,%d,%s\n",__LINE__,sqlite3_errcode(db),errmsg);
        return;
    }
    printf("user table create success!\n");
    load_db(db,FILE_PATH_TEST);
}

//调入词典数据
int load_db(sqlite3 *db,char *filepath)
{
    //首先检查词典数据库中有无数据，有数据就阻止导入
    char **pres = NULL;
    int row,column;
    char *errmsg = NULL;
    if(sqlite3_get_table(db,DICT_SELECT_SQL,&pres,&row,&column,&errmsg)!= SQLITE_OK)
    {
        fprintf(stderr,"server load_db query dictionary failed,__%d__,%d,%s\n",__LINE__,sqlite3_errcode(db),errmsg);
        return -1;
    }
    printf("server load_db query dictionary,row = %d,row =%d\n",row,column);
    if (row >= DICT_TEST_ROW)
    {
        printf("词典数据库中数据已存在!\n");
        return -1;
    }
    //1.以只读的方式打开文件
    FILE *fp = fopen(filepath,"r");
    if (NULL == fp)
    {
        ERR_MSG("dict source file open");
        return -1;
    }
    char buf[128] = {0};
    int16_t ret = 0;
    //读取数据，写入数据库
    char sql[128] = {0};
    
    if (NULL == fp)
    {
        ERR_MSG("dict source file open");
        return -1;
    }
    
    int num = 1;
    char word[64] = {0};
    char meaning[64] = {0};
    while (1)
    {
        bzero(word,sizeof(word));
        bzero(meaning,sizeof(meaning));
        bzero(buf,sizeof(buf));
        int m_index = 0;
        int j = 0;
        if (NULL == fgets(buf,sizeof(buf),fp))
        {
            printf("所有数据导入完毕，准备退出\n");
            sleep(1);
            break;
        } else
        {
            buf[strlen(buf)-1] = 0;
            //printf("[%d] %s\n",num,buf);
            //遍历buf，找到第一个空格
            for (int i = 0; i < strlen(buf); i++)
            {   
                word[i] = buf[i];
                if (buf[i] == ' ' && buf[i+1] == ' ' && buf[i+2] == ' ')
                {
                    word[i] = 0;
                    m_index = i+3;
                }
                if (0!=m_index)
                {
                    if (j < sizeof(meaning))
                    {
                        meaning[j] = buf[m_index];
                        m_index++;
                        j++;
                    }
                }
            }
            //构建sql插入数据
            sprintf(sql,WORD_INSERT_FORMAT,word,meaning);
            printf("[%d] sql=%s\n",num,sql);
            if (sqlite3_exec(db,sql,NULL,NULL,&errmsg)!= SQLITE_OK)
            {
                fprintf(stderr,"dict insert failed,__%d__,%d,%s\n",__LINE__,sqlite3_errcode(db),errmsg);
                return -1;
            }
            printf("[%d] %s  %s inserted ok\n",num,word,meaning);
            num++;
        }  
    }
     
    return 0;
}


void do_server_register(int newfd, msg_t *msg, sqlite3 *db)
{
    char sql[128] = {0};
    msg->status = 0;  //注册成功后用户处于未登录状态
    sprintf(sql,USER_INSERT_FORMAT,msg->name,msg->passwd,msg->status);
    printf("register sql = %s \n",sql);

    char *errmsg = NULL;
    if (sqlite3_exec(db,sql,NULL,NULL,&errmsg)!= SQLITE_OK)
    {
        fprintf(stderr,"insert user failed,__%d__,%d,%s\n",__LINE__,sqlite3_errcode(db),errmsg);
        //插入失败，返回用户名已存在
        strcpy(msg->text,"用户名已存在");
        return;
    } else
    {
        //插入成功，返回   返回插入成功
        //2. 发送消息给客户端
        strcpy(msg->text,"用户注册成功");
        ssize_t sret = send(newfd,msg,sizeof(msg_t),0);
        if (sret<0)
        {
            ERR_MSG("server do_server_register send");
            return;
        }
    } 
    return;
}


void do_server_login(int newfd, msg_t* msg, sqlite3 *db)
{
    char sql[128] = {0};
    sprintf(sql,USER_SELECT_FORMAT,msg->name,msg->passwd) ;
    printf("server do_server_login sql = %s \n",sql);
    char **pres = NULL;
    int row,column;
    char *errmsg = NULL;
    if(sqlite3_get_table(db,sql,&pres,&row,&column,&errmsg)!= SQLITE_OK)
    {
        fprintf(stderr,"sqlite3_get_table failed,__%d__,%d,%s\n",__LINE__,sqlite3_errcode(db),errmsg);
        return;
    }
    printf("server do_server_login,row = %d,row =%d\n",row,column);
    if (row <=0)
    {
        //用户不存在 ,提示 登录失败,账号/密码错误!
        strcpy(msg->text,"登录失败,账号/密码错误!");
        msg->status = 0; //登录成功状态码
        ssize_t sret = send(newfd,msg,sizeof(msg_t),0);
        if (sret<0)
        {
            ERR_MSG("server do_server_login send");
            return;
        }
    } else
    {
        //用户存在
        //查询数据库status=1 提示，请勿重复登录  status=0 登录成功，并将status置为1
        printf("server do_server_login pres[5]=%s\n",pres[5]);
        if (0==strcmp("1",pres[5]))
        {
            strcpy(msg->text,"登录失败,重复登录!!");
        } else if (0==strcmp("0",pres[5]))
        {
            strcpy(msg->text,"登录成功!");
            msg->status = 1; //登录成功状态码
            //更新数据库status字段
            char sql[128] = {0};
            sprintf(sql, USER_UPDATE_FORMAT,msg->status, msg->name);
            printf("server do_server_login sql = %s \n",sql);
            char *errmsg = NULL;
            if (sqlite3_exec(db,sql,NULL,NULL,&errmsg)!= SQLITE_OK)
            {
                fprintf(stderr,"server do_server_login failed,__%d__,%d,%s\n",__LINE__,sqlite3_errcode(db),errmsg);
                msg->status = 0;
                strcpy(msg->text,errmsg);
                ssize_t sret = send(newfd,msg,sizeof(msg_t),0);
                if (sret<0)
                {
                    ERR_MSG("server do_server_login send");
                    return;
                }
                return;
            }
            printf("%s server do_server_login 用户设置退出状态成功\n",msg->name);

        }
        ssize_t sret = send(newfd,msg,sizeof(msg_t),0);
        if (sret<0)
        {
            ERR_MSG("server do_server_login send");
            return;
        }
    }
}

void do_server_exit(int newfd,msg_t* msg,sqlite3 * db)
{
    char sql[128] = {0};
    sprintf(sql, USER_UPDATE_FORMAT,msg->status, msg->name);
    printf("server do_server_exit sql = %s \n",sql);
    char *errmsg = NULL;
    if (sqlite3_exec(db,sql,NULL,NULL,&errmsg)!= SQLITE_OK)
    {
        fprintf(stderr,"server do_server_exit failed,__%d__,%d,%s\n",__LINE__,sqlite3_errcode(db),errmsg);
        return;
    }
    printf("%s server do_server_exit 用户设置退出状态成功\n",msg->name);
}



//服务器查询单词
void do_server_word_query(int newfd,msg_t* msg,sqlite3 * db)
{
    char sql[256] = {0};
    sprintf(sql,DICT_SELECT_FORMAT,msg->text) ;
    printf("server do_server_word_query sql = %s \n",sql);
    char **pres = NULL;
    int row,column;
    char *errmsg = NULL;
    if(sqlite3_get_table(db,sql,&pres,&row,&column,&errmsg)!= SQLITE_OK)
    {
        fprintf(stderr,"server do_server_word_query failed,__%d__,%d,%s\n",__LINE__,sqlite3_errcode(db),errmsg);
        return;
    }
    printf("server do_server_word_query,row = %d,row =%d\n",row,column);
    if (row <=0)
    {
        //单词未查到 回复 NOT FOUND!!
        printf("单词 %s 的释义未查到\n",msg->text);
        strcpy(msg->text,"NOT FOUND!!");
        ssize_t sret = send(newfd,msg,sizeof(msg_t),0);
        if (sret<0)
        {
            ERR_MSG("server do_server_word_query send");
            return;
        }
    } else
    {
        //单词查到   
        //回复单词+释义
        strcat(msg->text,"\t");
        strcat(msg->text,pres[3]);
        printf("word and def to be sent to client==>%s\n",msg->text);
        ssize_t sret = send(newfd,msg,sizeof(msg_t),0);
        if (sret<0)
        {
            ERR_MSG("server do_server_word_query send");
            return;
        }
        //发送成功后插入历史记录表
        char sql[128] = {0};
        char time_buf[128] = {0}; 
        get_system_time(time_buf);
        sprintf(sql,HISTORY_INSERT_FORMAT,msg->name,pres[2],pres[3],time_buf);
        printf("do_server_word_query sql = %s \n",sql);

        char *errmsg = NULL;
        if (sqlite3_exec(db,sql,NULL,NULL,&errmsg)!= SQLITE_OK)
        {
            fprintf(stderr,"do_server_word_query insert history failed,__%d__,%d,%s\n",__LINE__,sqlite3_errcode(db),errmsg);
            return;
        }
        printf("用户 %s,单词 %s 插入历史记录成功\n",msg->name,pres[2]);
    }
}

//服务器查询历史记录
void do_server_history_query(int newfd,msg_t* msg,sqlite3 * db)
{
    
    char **pres = NULL;
    int row,column;
    char *errmsg = NULL;
    char sql[256] = {0};
    sprintf(sql,HISTORY_SELECT_FORMAT,msg->name);
    printf("server do_server_history_query sql = %s \n",sql);
    if(sqlite3_get_table(db,sql,&pres,&row,&column,&errmsg)!= SQLITE_OK)
    {
        fprintf(stderr,"server do_server_history_query failed,__%d__,%d,%s\n",__LINE__,sqlite3_errcode(db),errmsg);
        return;
    }
    printf("server do_server_history_query row = %d,column =%d\n",row,column);

    int count = 0;
    //row中不包含表头的一行，但是结果中有表头的内容，所以需要将表头的一行加上
    for (int i = 0; i < row+1; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if(i>0)
            {
                if (j>0)
                {
                    bzero(msg->text,sizeof(msg->text));
                    sprintf(msg->text,"%s\t",pres[count]);
                    //发送给客户端
                    ssize_t sret = send(newfd,msg,sizeof(msg_t),0);
                    if (sret<0)
                    {
                        ERR_MSG("server do_server_history_query send");
                        return;
                    }
                }
            }
            count++;
        }
        if(i > 0)
        {
            bzero(msg->text,sizeof(msg->text));
            strcpy(msg->text,"\n");
            //发送给客户端
            ssize_t sret = send(newfd,msg,sizeof(msg_t),0);
            if (sret<0)
            {
                ERR_MSG("server do_server_history_query send");
                return;
            }
        }
        
    }
    //发送结束标识给客户端
    strcpy(msg->text,"**OVER**\n");
    //发送给客户端
    ssize_t sret = send(newfd,msg,sizeof(msg_t),0);
    if (sret<0)
    {
        ERR_MSG("server do_server_history_query send");
        return;
    }

}

//获取当前系统时间
void get_system_time(char *time_buf)
{
    time_t cur_systime_milli = time(NULL);
    struct tm *t = localtime(&cur_systime_milli);
    sprintf(time_buf,"%4d-%02d-%02d %02d-%02d-%02d",
    t->tm_year+1900,t->tm_mon+1,t->tm_mday,t->tm_hour,
    t->tm_min,t->tm_sec);
}

//回收僵尸进程
void handler(int sig)
{
    while (waitpid(-1,NULL,WNOHANG)>0); //循环回收僵尸进程
}