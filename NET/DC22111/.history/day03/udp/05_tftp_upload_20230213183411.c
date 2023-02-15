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
#define SER_IP "192.168.8.76"  //ifconfig

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

    //发送上传请求给服务器，服务器IP widowsIP   port:69
    char buf[516]={0};
    char send_buf[512] = {0};
    char ack_buf[4]={0};
    short *p1 = (short *)buf;
    *p1 = htons(2);  //上传
    char *p2 = buf + 2;
    strcpy(p2,"01_udp_server.c"); //文件名 ==>终端拿 1_udpSer.c
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

    //只读模式打开文件，用于上传
    ssize_t ret = 0;
    ssize_t ret1 = 0;
    int fd = open("01_udp_server.c",O_RDONLY); //只读不需权限
    if (fd < 0)
    {
        ERR_MSG("open");
        return -1;
    }
    
    while (1)
    {
        bzero(buf,sizeof(buf));
        //循环接收数据包  recvfrom
        //服务器发送确认数据包，在数据包中它使用编号0
        ret = recvfrom(sfd,ack_buf,sizeof(ack_buf),0,(struct sockaddr *)&sin,&addrlen);
        printf("ret = %ld\n",ret);
        if (ret < 0)
        {
            ERR_MSG("recvfrom");
            return -1;
        }
        printf("ack data package operate code: %d ,block no: %d \n",ntohs(*(short *)ack_buf),ntohs(*((short *)ack_buf+1)));

        /*
        //测试代码    操作码是 4 编号从 0 开始
        printf("data package operate code: %d ,block no: %d ",ntohs(*(short *)ack_buf),ntohs(*((short *)ack_buf+1)));
        break;
        */

        //从文件中读取数据，开始向服务器发送
        ret1 = read(fd,send_buf,sizeof(send_buf));
        /*
        测试
        for (int i = 0; i < sizeof(send_buf); i++)
        {
            printf("%c",send_buf[i]);
        }
        break;
        */
        printf("ret1 = %ld\n",ret1);
        //将数据包组装，发送至服务器 sendto
        *(short *)buf = htons(3); //数据包操作码为3
        *((short *)buf+1) = *((short *)ack_buf+1) + htons(1);    //块编号
        //拷贝
        strcpy(buf+4,send_buf);
        
        //测试
        for (int i = 0; i < 516; i++)
        {
            printf("%c",buf[i]);
        }
        break;
        
        
        if(sendto(sfd,buf,sizeof(buf),0,(struct sockaddr *)&sin,addrlen) < 0)
        {
            ERR_MSG("sendto");
            return -1;
        }
        printf("sendto success\n");
        //上传数据小于 512字节，结束循环，上传完毕
        if (ret1 < 512)
        {
            printf("上传完毕\n");
            break;
        }
    }

    printf("file size = %ld\n",lseek(fd,0,SEEK_END));


    return 0;
}
