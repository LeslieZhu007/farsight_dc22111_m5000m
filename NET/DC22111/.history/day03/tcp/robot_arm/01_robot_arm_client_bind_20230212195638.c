#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define SER_PORT 7777 //1024-49151
#define SER_IP "192.168.8.177"  //ifconfig

#define CLI_PORT 4444   //客户端需要绑定的端口号
#define CLI_IP "192.168.8.177"

#define ERR_MSG(msg) do {\
    fprintf(stderr,"line: __%d__ ",__LINE__);\
    perror(msg);\
} while (0)

int main(int argc, char const *argv[])
{
    //1. 创建流式套接字
    int cfd = socket(AF_INET,SOCK_STREAM,0);
    if (cfd < 0)
    {
        ERR_MSG("socket");
        return -1;
    }
    
    
    //2. 绑定科幻段自身的地址信息结构体---->非必须绑定,可以选择不绑
    //如果选择不绑定，则操作系统会默认绑定一个端口号给这个客户端

    //填充客户端自身的IP和端口
    /*
    struct sockaddr_in cin;
    cin.sin_family = AF_INET; //必须填AF_INET
    cin.sin_port = htons(CLI_PORT); //服务器绑定的端口号
    cin.sin_addr.s_addr = inet_addr(CLI_IP); //服务器绑定的IP
    if(bind(cfd,(struct sockaddr *)&cin,sizeof(cin)) < 0)
    {
        ERR_MSG("bind");
        return -1;
    }
    printf("bind success\n");
    */

    //填充要连接的服务器的ip和端口
    struct sockaddr_in sin;
    sin.sin_family = AF_INET; //必须填AF_INET
    sin.sin_port = htons(SER_PORT); //服务器端绑定的端口号
    sin.sin_addr.s_addr = inet_addr(SER_IP); //服务器端绑定的IP
    //3. 连接服务器   int connect(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
    
    if(connect(cfd,(struct sockaddr *)&sin,sizeof(sin)) < 0)
    {
        ERR_MSG("connect");
        return -1;
    }

    printf("connect success\n");

    char buf[5] = {0xff,0x02,0x00,-70,0xff};  //unsigned char a : 0x00 ~ 0xff
    ssize_t ret = 0;
    if(write(cfd,buf,sizeof(buf)) < 0)
    {
        ERR_MSG("send");
        return -1;
    }
    printf("send success\n");

    while (1)
    {
        //从终端输入 wasd 按钮

        //输入w，红色手臂++ 输入s 红色手臂 --
        //输入a , 蓝色手臂-- 输入d 蓝色手臂++
    }
    
       

    //6. 关闭文件描述符
    close(cfd);

    return 0;
}
