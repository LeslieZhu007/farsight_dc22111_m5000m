#include "udpchat.h"


int main(int argc, char const *argv[])
{
    
    //1.创建报式套接字   socket
    int sfd = socket(AF_INET,SOCK_DGRAM,0);
    if (sfd < 0)
    {
        ERR_MSG("socket");
        return -1;
    }

    //服务器自身的地址信息结构体，真实的地址信息结构体根据AF_INET查找
    struct sockaddr_in cin;
    cin.sin_family = AF_INET;
    cin.sin_port = htons(SERVER_PORT);
    cin.sin_addr.s_addr = inet_addr(SERVER_IP);


    char buf[128] = {0};
    ssize_t ret = 0;

    struct sockaddr_in sin; //存储发送方的地址信息
    socklen_t addrlen = sizeof(sin);

    pid_t cpid;

    cpid = fork();
    if(cpid > 0)
    {
        while (1)
        {
            //父进程用于发送
            bzero(buf,sizeof(buf));
            //将数据发送给服务器
            printf("请输入想要发送的数据:");
            fgets(buf,sizeof(buf),stdin);
            buf[strlen(buf)-1] = 0;
            if(sendto(sfd,buf,sizeof(buf),0,(struct sockaddr *)&cin,sizeof(cin)) < 0)
            {
                ERR_MSG("sendto");
                return -1;
            }
            printf("sendto success\n");
        }
    } else if(cpid == 0)
    {
        while (1)
        {
            //子进程用于接收
            bzero(buf,sizeof(buf));
            ret = recvfrom(sfd,buf,sizeof(buf),0,(struct sockaddr *)&sin,&addrlen);
            if (ret < 0)
            {
                ERR_MSG("recvfrom");
                return -1;
            } 
            printf("[%s:%d] :%s\n",inet_ntoa(sin.sin_addr),ntohs(sin.sin_port),buf);
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
