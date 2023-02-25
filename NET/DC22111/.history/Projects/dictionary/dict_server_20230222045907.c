#include "dictionary.h"



int main_1(int argc, char const *argv[])
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


    struct sockaddr_in cin; //存储客户端的地址信息
    socklen_t addrlen = sizeof(cin);
    int newfd = 0;
    int cpid = 0;
    while (1)
    {
        //父进程只负责连接
        //4. accept:阻塞函数，阻塞等待客户端连接成功
            //当客户端连接成功后,会从已完成连接的队列头中获取一个客户端信息
            //并生成一个新的文件描述符
            //注意: 新生成的文件描述符才是用于通信的文件描述符
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
            deal_cli_inter(newfd,cin);
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

int deal_cli_inter(int newfd,struct sockaddr_in cin)
{
    //通过文件描述符，读取数据
    //原型 ssize_t recv(int sockfd, void *buf, size_t len, int flags);
    char buf[128] = "";
    ssize_t  ret = 0;
    while (1)
    {
        bzero(buf,sizeof(buf));
        ret = recv(newfd,buf,sizeof(buf),0);
        if (ret < 0)
        {
            ERR_MSG("recv");
            break;
        } else if (0 == ret)
        {
            printf("[%s | %d] newfd = %d 客户端断开连接\n",inet_ntoa(cin.sin_addr),ntohs(cin.sin_port),newfd);
            break;
        }
        
        printf("%ld: %s\n",ret,buf);
        //TODO 发送 ----> 谁发给我数据，就发还给谁
        //ssize_t send(int sockfd, const void *buf, size_t len, int flags);
        strcat(buf,"*_*");
        if (send(newfd,buf,sizeof(buf),0) < 0)
        {
            ERR_MSG("send");
            return -1;
        }
        printf("send success\n");
    }
    close(newfd);
    return 0;
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

void database_init(sqlite3 *db)
{
    //创建数据库
    if(sqlite3_open(DB_NAME,&db)!= SQLITE_OK)
    {
        fprintf(stderr,"database create failed,__%d__,%d,%s\n",__LINE__,sqlite3_errcode(db),
        sqlite3_errmsg(db));
        return;
    }
    printf("database create success!\n");

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

int load_db(sqlite3 *db,char *filepath)
{
    
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
    char *errmsg = NULL;
    char word[32] = {0};
    char meaning[64] = {0};
    while (1)
    {
    
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
    }  
    return 0;
}

