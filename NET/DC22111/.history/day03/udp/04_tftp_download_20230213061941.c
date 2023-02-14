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

#define SER_PORT 69 //1024-49151
#define SER_IP "192.168.8.177"  //ifconfig

#define ERR_MSG(msg) do {\
    fprintf(stderr,"line: __%d__ ",__LINE__);\
    perror(msg);\
} while (0)

int main(int argc, char const *argv[])
{
    
    
    //创建报式套接字
    //1.创建宝石套接字   socket
    int sfd = socket(AF_INET,SOCK_DGRAM,0);
    if (sfd < 0)
    {
        ERR_MSG("socket");
        return -1;
    }

    //绑定，非必须绑定

    
    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(SER_PORT);
    sin.sin_addr.s_addr = inet_addr(SER_IP);
    socklen_t addrlen = sizeof(sin);

    


    //发送下载请求给服务器，服务器IP widowsIP   port:69
    char buf[516]={0};
    char ack_buf[4]={0};
    short *p1 = (short *)buf;
    *p1 = htons(1);  //下载
    char *p2 = buf + 2;
    strcpy(p2,"5.png"); //文件名 ==>终端拿 1_udpSer.c
    //strcpy(p2,"1_udpSer.c"); 
    char  *p3 = p2+strlen(p2);
    *p3 = 0;

    char *p4 = p3+1;
    strcpy(p4,"octet");

    char *p5 = p4+strlen(p4);
    *p5 = 0;

    int size = 2+strlen(p2) + 1 + strlen(p4) + 1;
    if(sendto(sfd,buf,size,0,(struct sockaddr *)&sin,sizeof(sin)) < 0)
    {
        ERR_MSG("send to");
        return -1;
    }
    printf("send protocol success\n");

    ssize_t ret = 0;
    int fd = open("5.png",O_WRONLY|O_CREAT|O_TRUNC);
    //int fd = open("1_udpSer.c",O_WRONLY|O_CREAT|O_TRUNC);
    if (fd < 0)
    {
        ERR_MSG("open");
        return -1;
    }
    
    while (1)
    {
        bzero(buf,sizeof(buf));
        //循环接收数据包  recvfrom
        ret = recvfrom(sfd,buf,sizeof(buf),0,(struct sockaddr *)&sin,&addrlen);
        printf("ret = %ld\n",ret);
        if (ret < 0)
        {
            ERR_MSG("recvfrom");
            return -1;
        }
        /*
        测试代码
        printf("data package operate code: %d ,block no: %d ",ntohs(*(short *)buf),ntohs(*((short *)buf+1)));
        break;
        */
        //从数据包中提取数据，存储到文件中
        ssize_t ret1 = write(fd,buf+4,ret-4);
        /*
        测试
        for (int i = 0; i < ret-4; i++)
        {
            printf("%c",(buf+4)[i]);
        }
        break;
        */
        printf("ret1 = %ld\n",ret1);
        //回复应答包 sendto
        *(short *)ack_buf = htons(4);
        *((short *)ack_buf+1) = *((short *)buf+1);
        if(sendto(sfd,ack_buf,sizeof(ack_buf),0,(struct sockaddr *)&sin,addrlen) < 0)
        {
            ERR_MSG("sendto");
            return -1;
        }
        printf("sendto success\n");
        //知道数据大小小于 512字节，结束循环，下载完毕
        if (ret-4 < 512)
        {
            printf("下载完毕\n");
            break;
        }
    }
    

    

    printf("file size = %ld\n",lseek(fd,0,SEEK_END));


    return 0;
}
