#include "udpchat.h"

//回收僵尸进程
void handler(int sig);

int main(int argc, char const *argv[])
{
    //捕获17号信号，注册新的处理函数，用于回收僵尸进程
    __sighandler_t s = signal(SIGCHLD,handler);
    if (SIG_ERR == s)
    {
        printf("signal");
        return -1;
    }

    //1.创建报式套接字   socket
    int sfd = socket(AF_INET,SOCK_DGRAM,0);
    if (sfd < 0)
    {
        ERR_MSG("socket");
        return -1;
    }

    //服务器自身的地址信息结构体，真实的地址信息结构体根据AF_INET查找
    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(SERVER_PORT);
    sin.sin_addr.s_addr = inet_addr(SERVER_IP);


    char buf[128] = {0};
    ssize_t ret = 0;

    struct sockaddr_in cin; //存储发送方的地址信息
    socklen_t addrlen = sizeof(cin);
    pid_t cpid;

    protocol_t protocol;
    memset(&protocol,0,sizeof(protocol));

    //进行登录操作,输入用户名
    printf("请输入用户名>>");
    fgets(protocol.name,NAME_LENGTH,stdin);
    protocol.name[strlen(protocol.name)-1] = 0;
    //构造发送消息结构体发送给服务器
    protocol.type = 'L';
    //发送登录信息
    if(sendto(sfd,&protocol,sizeof(protocol),0,(struct sockaddr *)&sin,sizeof(sin)) < 0)
    {
        ERR_MSG("sendto");
        return -1;
    }
    printf("client send login info to server success\n");

    //登录成功后创建父子进程进行: 1.发送聊天信息，退出信息  2.
    cpid = fork();
    if(cpid > 0)
    {
        while (1)
        {
            bzero(&protocol,sizeof(protocol));
            //父进程用于发送
            //1.聊天信息
            //2.退出==> 输入quit 退出
            fgets(protocol.text,TEXT_LENGTH,stdin);
            protocol.text[strlen(protocol.text)-1] = 0;
            if (0 == strcmp(protocol.text,"quit") )
            {
                protocol.type = 'Q';
            } else
            {
                protocol.type = 'C';
            }
            //发送
            if(sendto(sfd,&protocol,sizeof(protocol),0,(struct sockaddr *)&sin,sizeof(sin)) < 0)
            {
                ERR_MSG("sendto");
                return -1;
            }
            printf("chatting msg sent to server success\n");
        }
    } else if(cpid == 0)
    {
        while (1)
        {
            //子进程用于接收客户端发来的数据
            bzero(&protocol,sizeof(protocol));
            ret = recvfrom(sfd,&protocol,sizeof(protocol),0,(struct sockaddr *)&cin,&addrlen);
            if (ret < 0)
            {
                ERR_MSG("recvfrom");
                return -1;
            } 
            //打印接收到的信息
            switch (protocol.type)
            {
                case 'L':
                    printf("%s已登录...\n",protocol.name);
                    break;
                case 'C':
                    printf("%s:%s\n",protocol.name,protocol.text);
                    break;
                case 'Q':
                    printf("%s已退出...\n",protocol.name);
                    break;
                
                default:
                    break;
            }
        }
    } else
    {
        ERR_MSG("fork");
        return -1;
    }
    //5.关闭套接字文件描述符
    close(sfd);

    return 0;
}


void handler(int sig)
{
    while (waitpid(-1,NULL,WNOHANG)>0); //循环回收僵尸进程
}

