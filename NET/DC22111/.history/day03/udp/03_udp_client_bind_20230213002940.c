#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/input.h>
#include <stdlib.h>

#define SER_PORT 8888 //1024-49151
#define SER_IP "192.168.8.249"  //ifconfig

#define CLI_PORT 8887 //1024-49151
#define CLI_IP "192.168.8.249"  //ifconfig

#define ERR_MSG(msg) do {\
    fprintf(stderr,"line: __%d__ ",__LINE__);\
    perror(msg);\
} while (0)

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
    //man 7 ip
    //供给sendto函数使用
    struct sockaddr_in cin;
    cin.sin_family = AF_INET;
    cin.sin_port = htons(SER_PORT);
    cin.sin_addr.s_addr = inet_addr(SER_IP);


    //2.绑定客户端的地址信息结构体  bind  绑定为非必须
    //填充客户端的地址信息结构体
    struct sockaddr_in clientaddr;
    clientaddr.sin_family = AF_INET;
    clientaddr.sin_port = htons(CLI_PORT);
    clientaddr.sin_addr.s_addr = inet_addr(CLI_IP);
    
    if(bind(sfd,(struct sockaddr *)&clientaddr,sizeof(clientaddr)) < 0)
    {
        ERR_MSG("bind");
        return -1;
    }
    printf("udp server bind success\n");
    

    char buf[128] = {0};
    ssize_t ret = 0;

    struct sockaddr_in sin; //存储发送方的地址信息
    socklen_t addrlen = sizeof(sin);

    while (1)
    {
        bzero(buf,sizeof(buf));
        //4.将数据发送给服务器
        printf("请输入想要发送的数据:");
        fgets(buf,sizeof(buf),stdin);
        buf[strlen(buf)-1] = 0;
        if(sendto(sfd,buf,sizeof(buf),0,(struct sockaddr *)&cin,sizeof(cin)) < 0)
        {
            ERR_MSG("sendto");
            return -1;
        }
        printf("sendto success\n");
        
        ret = recvfrom(sfd,buf,sizeof(buf),0,(struct sockaddr *)&sin,&addrlen);
        if (ret < 0)
        {
            ERR_MSG("recvfrom");
            return -1;
        }
        printf("[%s:%d] :%s\n",inet_ntoa(sin.sin_addr),ntohs(sin.sin_port),buf);

        
    }
    

    //5.关闭套接字文件描述符
    close(sfd);

    return 0;
}
