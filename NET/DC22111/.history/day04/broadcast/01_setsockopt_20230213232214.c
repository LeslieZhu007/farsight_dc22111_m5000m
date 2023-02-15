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

/*
 int getsockopt(int sockfd, int level, int optname,void *optval, socklen_t *optlen);


int setsockopt(int sockfd, int level, int optname,const void *optval, socklen_t optlen);
*/




int main(int argc, char const *argv[])
{
    int sfd = socket(AF_INET,SOCK_DGRAM,0);
    if (sfd < 0)
    {
        perror("socket");
        return -1;
    }
    //获取接收缓冲区的大小
    int rcvbuf = 0;
    socklen_t optlen = sizeof(rcvbuf);
    if(getsockopt(sfd,SOL_SOCKET,SO_RCVBUF,&rcvbuf,&optlen) < 0)
    {
        perror("getsockopt");
        return -1;
    }

    printf("rcvbuf = %d bytes %dkb\n",rcvbuf,rcvbuf/1024);

    //设置端口快速重用
    int reuse = 1;
    if(setsockopt(sfd,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(int))<0)
    {
        perror("setsockopt");
        return -1;
    }
    printf("setsockopt success\n");


    //设置允许广播
    setsockopt(sfd,SOL_SOCKET,SO_BROADCAST,)
    
    return 0;
}
