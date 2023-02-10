#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <arpa/inet.h>
#include <string.h>

#define PORT 8888 //1024-49151
#define IP "192.168.43.26"  //ifconfig
#define ERR_MSG(msg) do {\
    fprintf(stderr,"line: __%d__ ",__LINE__);\
    perror(msg);\
} while (0)

/*
    struct sockaddr_in {
        sa_family_t    sin_family; // address family: AF_INET   
        in_port_t      sin_port;   // port in network byte order   1024~49151
        struct in_addr sin_addr;   // internet address  网络字节序 填本机IP
    };
    //Internet address. 
    struct in_addr {
        uint32_t       s_addr;     // address in network byte order 
    };
*/


int main(int argc, char const *argv[])
{
    //创建流式套接字  -->> TCP
    int sfd =  socket(AF_INET, SOCK_STREAM, 0);
    if (sfd < 0)
    {
        ERR_MSG("socket");
        return -1;
    }

    //填充地址信息结构体，真实的地址信息结构体在man 7 ip
    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORT); //1024~49151 网络字节序
    sin.sin_addr.s_addr = inet_addr(IP);

    //功能
    if(bind(sfd, (const struct sockaddr *)&sin,sizeof(sin)) < 0)
    {
        ERR_MSG("bind");
        return -1;
    }
    printf("bind success __%d__\n",__LINE__);

    //将套接字设置为被动监听状态，只负责监听是否有客户端连接成功

    if(listen(sfd,10) <0)
    {
        ERR_MSG("listen");
        return -1;
    }
    printf("listen success __%d__\n",__LINE__);

    //accept:阻塞函数，阻塞等待客户端连接成功
             //当客户端连接成功后
    struct sockaddr_in cin; //存储客户端的地址信息
    socklen_t addrlen = sizeof(cin);
    int newfd = 0;
    newfd =  accept(sfd,(struct sockaddr *)&cin,&addrlen);
    if (newfd < 0)
    {
        ERR_MSG("accept");
        return -1;
    }
    printf("[%s | %d] newfd = %d\n",inet_nota(cin.sin_addr),ntohs(cin.sin_port),newfd);


    //通过文件描述符，读取数据

    ssize_t recv(int sockfd, void *buf, size_t len, int flags);
    char buf[128] = "";
    ssize_t  ret = 0;
    while (1)
    {
        bzero(buf,sizeof(buf));
        ret = recv(newfd,buf,sizeof(buf),0);
        if (ret < 0)
        {
            ERR_MSG("recv");
            return -1;
        }
        
    }
    
    
    return 0;
}
