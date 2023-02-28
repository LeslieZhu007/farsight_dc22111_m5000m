#include "dictionary.h"
/*
typedef struct _msg 
{
    char name[20];
    char passwd[20];
    char text[128];
    int type;  //1.注册 2.登录 3.退出 4.查单词 5.查历史记录
} msg_t;
*/



int main(int argc, char const *argv[])
{

    /*****抽取函数******连接服务器部分 begin***************************/
    //1. 创建流式套接字
    int cfd = socket(AF_INET,SOCK_STREAM,0);
    if (cfd < 0)
    {
        ERR_MSG("socket");
        return -1;
    }
    //填充要连接的服务器的ip和端口
    struct sockaddr_in sin;
    sin.sin_family = AF_INET; //必须填AF_INET
    sin.sin_port = htons(PORT); //服务器绑定的端口号
    sin.sin_addr.s_addr = inet_addr(IP); //服务器绑定的IP
    //3. 连接服务器   int connect(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
    if(connect(cfd,(struct sockaddr *)&sin,sizeof(sin)) < 0)
    {
        ERR_MSG("connect");
        return -1;
    }
    printf("connect success\n");
/*******************连接服务器部分 end***************************/

/*********************主逻辑部分*********************************/
    char choose = 0;
    while (1)
    {
        msg_t msg;
        print_1st_level_menu();
        choose = getchar();
        while (getchar()!=10);
        switch (choose)
        {
            case '1':
                do_register(cfd,&msg);
                break;
            case '2':
                do_login(cfd,&msg);
                break;
            case '3':
                goto END; //服务器提示断开连接
                break;
            default:
                printf("输入错误，请重新输入\n");
        }
        //请按任意键清屏
        printf("请按任意键清屏\n");
        while (getchar()!=10);
        system("clear");
    }

END:
    close(cfd);
    return 0;
}


void print_1st_level_menu()
{
    printf("..................主界面.....................\n");
    printf(".................1.注册.......................\n");
    printf(".................2.登录.......................\n");
    printf(".................3.退出.......................\n");
    printf(".............................................\n");
    printf("请输入你的选择>>");
}

void print_2nd_level_menu()
{
    printf("........................................\n");
    printf("............1.查单词.......................\n");
    printf("............2.历史记录.......................\n");
    printf("............3.返回上一级.......................\n");
    printf(".............................................\n");
    printf("请输入你的选择>>");
}


//客户端注册功能
void do_register(int cfd,msg_t* msg)
{
     //1. 构造发送消息结构体
    bzero(msg,sizeof(msg));
    msg->type = 1; //注册
    printf("请输入账户名>>>");
    fscanf(stdin,"%s",msg->name);
    while (getchar()!=10);
    printf("请输入密码>>>");
    fscanf(stdin,"%s",msg->passwd);
    while (getchar()!=10);
    //2. 发送消息给服务器
    ssize_t sret = send(cfd,msg,sizeof(msg_t),0);
    if (sret<0)
    {
        ERR_MSG("client do_register send");
        return;
    }
    //3.接收服务器返回的消息
    ssize_t rret = recv(cfd,msg,sizeof(msg_t),0);
    if (rret<0)
    {
        ERR_MSG("client do_register recv");
        return;
    }
    //4.返回的消息判断是否注册成功
    printf("%s\n",msg->text);
}

//客户端登录功能
void do_login(int cfd,msg_t *msg)
{
    //1. 构造发送消息结构体
    bzero(msg,sizeof(msg_t));
    msg->type = 2; //登录
    printf("请输入登录账户名>>>");
    fscanf(stdin,"%s",msg->name);
    while (getchar()!=10);
    printf("请输入登录密码>>>");
    fscanf(stdin,"%s",msg->passwd);
    while (getchar()!=10);
    //2. 发送消息给服务器
    ssize_t sret = send(cfd,msg,sizeof(msg_t),0);
    if (sret<0)
    {
        ERR_MSG("client do_login send");
        return;
    }
    //3.接收服务器返回的消息
    ssize_t rret = recv(cfd,msg,sizeof(msg_t),0);
    if (rret<0)
    {
        ERR_MSG("client do_login recv");
        return;
    }
    //根据返回消息结构体判断登录是否成功
    //失败，提示错误原因，返回一级菜单==> 继续往下走
    if (0==msg->status)
    {
        printf("%s\n",msg->text);
        return;
    } else if (1==msg->status)
    {
        //成功进入二级菜单
        char choose = 0;
        while (1)
        {
            print_2nd_level_menu();
            choose = getchar();
            while (getchar()!=10);
            switch (choose)
            {
                case '1':   //==> 4
                    do_query_word(cfd,msg);
                    break;
                case '2':   //==> 5
                    do_query_history(cfd,msg);
                    break;
                case '3':     //6.返回上一级
                    //给服务发送用户退出标识
                    set_user_exit_status(cfd,msg);
                    return;
                default:
                    printf("输入错误，请重新输入\n");
            }
            //请按任意键清屏
            printf("请按任意键清屏\n");
            while (getchar()!=10);
            system("clear");
        }
    }
}

void set_user_exit_status(int cfd,msg_t *msg)
{
    //把登录状态位置为0
    msg->status = 0;
    msg->type = 3;
    //2. 发送消息给服务器
    ssize_t sret = send(cfd,msg,sizeof(msg_t),0);
    if (sret<0)
    {
        ERR_MSG("client set_user_exit_status send");
        return;
    }
    /*
    //3.接收服务器返回的消息
    ssize_t rret = recv(cfd,&msg,sizeof(msg),0);
    if (rret<0)
    {
        ERR_MSG("client do_login recv");
        return;
    }
    */
}

//客户端查单词
void do_query_word(int cfd,msg_t *msg)
{
    while (1)
    {
        bzero(msg->text,sizeof(msg->text));
        printf("请输入单词(输入#退出)>>>");
        fscanf(stdin,msg->text,sizeof(msg->text));
        while (getchar()!=10);
        if (strcmp(msg->text,"#")==0)
        {
            return;
        }
        msg->type = 4;
        //2. 发送消息给服务器
        ssize_t sret = send(cfd,msg,sizeof(msg_t),0);
        if (sret<0)
        {
            ERR_MSG("client do_login send");
            return;
        }
        //3.接收服务器返回的消息
        bzero(msg->text,sizeof(msg->text));
        ssize_t rret = recv(cfd,msg,sizeof(msg_t),0);
        if (rret<0)
        {
            ERR_MSG("client do_login recv");
            return;
        }
        printf("%s\n",msg->text);
    }
}


//客户端查历史记录
void do_query_history(int cfd,msg_t *msg)
{
    msg->type = 5;
    //2. 发送消息给服务器
    ssize_t sret = send(cfd,msg,sizeof(msg_t),0);
    if (sret<0)
    {
        ERR_MSG("client do_login send");
        return;
    }
    //3.循环接收服务器返回的消息
    while (1)
    {
        ssize_t rret = recv(cfd,msg,sizeof(msg_t),0);
        if (rret<0)
        {
            ERR_MSG("client do_login recv");
            return;
        }
        printf("%s\n",msg->text);
        if (0==strcmp("**OVER**",msg->text))
        {
            break;
        }
    }
    
    
}
