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
#include <sys/un.h>

#define ERR_MSG(msg) do {\
    fprintf(stderr,"line: __%d__ ",__LINE__);\
    perror(msg);\
} while (0)

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr,"请输入客户端套接字文件名");
        return -1;
    }
    
    //1.创建报式套接字   socket
    int sfd = socket(AF_UNIX,SOCK_DGRAM,0);
    if (sfd < 0)
    {
        ERR_MSG("socket");
        return -1;
    }

    //服务器自身的地址信息结构体，真实的地址信息结构体根据AF_INET查找
    //man 7 ip
    //供给sendto函数使用
    struct sockaddr_un sun;
    sun.sun_family = AF_UNIX;
    strcpy(sun.sun_path,argv[1]);
    //2.绑定服务器的地址信息结构体  bind  域套接字客户端必须绑定，
    

    if (access(argv[1],F_OK)==0)
    {
         //如果存在，删除套接字文件
        if (unlink(argv[1]) < 0)
        {
            ERR_MSG("ulink");
            return -1;
        }
    }
    struct sockaddr_un cun;
    cun.sun_family = AF_UNIX;
    strcpy(cun.sun_path,"./udpunix1"); //客户端自己的
    if(bind(sfd,(struct sockaddr *)&cun,sizeof(cun)) < 0)
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
