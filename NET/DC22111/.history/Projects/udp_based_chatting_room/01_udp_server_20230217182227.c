#include "udpchat.h"


int main(int argc, char const *argv[])
{
    //1.创建宝石套接字   socket
    int sfd = socket(AF_INET,SOCK_DGRAM,0);
    if (sfd < 0)
    {
        ERR_MSG("socket");
        return -1;
    }

    //服务器自身的地址信息结构体，真实的地址信息结构体根据AF_INET查找
    //man 7 ip
    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(SERVER_PORT);
    sin.sin_addr.s_addr = inet_addr(SERVER_IP);
    //2.绑定服务器的地址信息结构体  bind
    if(bind(sfd,(struct sockaddr *)&sin,sizeof(sin)) < 0)
    {
        ERR_MSG("bind");
        return -1;
    }
    printf("udp server bind success\n");




    char buf[128] = {0};
    ssize_t ret = 0;

    struct sockaddr_in cin;
    socklen_t addrlen = sizeof(cin);

    pid_t cpid;

    cpid = fork();
    if(cpid > 0)
    {
        //父进程接收
        while (1)
        {
            bzero(buf,sizeof(buf));
            ret = recvfrom(sfd,buf,sizeof(buf),0,(struct sockaddr *)&cin,&addrlen);
            if (ret < 0)
            {
                ERR_MSG("recvfrom");
                return -1;
            }
            printf("[%s:%d] :%s\n",inet_ntoa(cin.sin_addr),ntohs(cin.sin_port),buf);
        }

    } else if(cpid == 0)
    {
        //子进程发送
        while (1)
        {
            strcat(buf,"*_*\n");
            if(sendto(sfd,buf,sizeof(buf),0,(struct sockaddr *)&cin,sizeof(cin)) < 0)
            {
                ERR_MSG("sendto");
                return -1;
            }
            printf("sendto success\n");
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
