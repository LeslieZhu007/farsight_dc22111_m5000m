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

int do_download(int sfd,struct sockaddr_in sin);

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
    

    int choose = 0;
    while (1)
    {
        printf("****************************************\n");
        printf("***********1.下载*************************\n");
        printf("***********2.上传***********************\n");
        printf("***********3.退出***********************\n");
        printf("****************************************\n");
        printf("请输入>>>");
        scanf("%d",&choose);
        while (getchar()!=10);
        switch (choose)
        {
        case 1:
            do_download(sfd,sin);
            break;
        case 2:
            //do_upload();
            break;
        case 3:
            goto END;
            break;
        
        default:
            printf("请重新输入\n");
        }
    }

END:
    return 0;
}


int do_download(int sfd,struct sockaddr_in sin)
{
    socklen_t addrlen = sizeof(sin);
 //发送下载请求给服务器，服务器IP widowsIP   port:69
    char buf[516]={0};
    char filename[20] = {0};
    char ack_buf[4]={0};
    short *p1 = (short *)buf;
    *p1 = htons(1);  //下载
    char *p2 = buf + 2;
    scanf("%s",filename);
    while (getchar()!=10); //循环吸收垃圾字符
    strcpy(p2,filename); //文件名 ==>终端拿 1_udpSer.c
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
    
    int flag = 0;
    int fd;
    unsigned short num = 0; //记录本地数据包编号
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
        if (3 == buf[1])
        {
            //由于udp不稳定，数据可能重复到达或者失序，所以本地需要记录数据包
            //编号，存储在num中，如果数据包中的块编号与本地记录的一致，
            //则说明是正确的需要存储的包
            if (htons(num+1) == *(unsigned short *)(buf+2))
            {
                /* code */
            }
            
            if (0==flag)
            {
                fd = open(filename,O_WRONLY|O_CREAT|O_TRUNC,0664); //权限不能少
                if (fd < 0)
                {
                    ERR_MSG("open");
                    return -1;
                }
                flag++;
            }
            
                /*
                测试代码
                printf("data package operate code: %d ,block no: %d ",ntohs(*(short *)buf),ntohs(*((short *)buf+1)));
                break;
                */
                //从数据包中提取数据，存储到文件中
                //由于最后一次的数据肯定会小于512，所以写入的数据大小不能填512
                //而是获取到的实际包的大小-4
                ssize_t ret1 = write(fd,buf+4,ret-4);
                printf("ret1 = %ld\n",ret1);
                //回复应答包 sendto
                /*
                *(short *)ack_buf = htons(4);
                *((short *)ack_buf+1) = *((short *)buf+1);
                if(sendto(sfd,ack_buf,sizeof(ack_buf),0,(struct sockaddr *)&sin,addrlen) < 0)
                */
                buf[1] = 4;  //只发4个字节
                if(sendto(sfd,buf,4,0,(struct sockaddr *)&sin,addrlen) < 0)
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
        } else if(5 == buf[1])
        {

        }
    
        
    }

    printf("file size = %ld\n",lseek(fd,0,SEEK_END));
    close(fd);
    return 0;
}