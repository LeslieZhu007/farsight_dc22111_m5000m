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
#include <time.h>

#define PORT 8888 //接收方绑定的一致即可
#define IP "192.168.8.255"  //广播IP
#define ERR_MSG(msg) do {\
    fprintf(stderr,"line: __%d__ ",__LINE__);\
    perror(msg);\
} while (0)



int main(int argc, char const *argv[])
{
    //广播的发送方流程 -->类似UDP的客户端
    //1.socket 创建报式套接字
    int sfd = socket(AF_INET,SOCK_DGRAM,0);
    if (sfd < 0)
    {
        ERR_MSG("socket");
        return -1;
    }

    //setsockopt  设置允许广播，默认式不允许广播，所以要设置允许广播
    // level SOL_SOCKET  optname:  SO_BROADCAST
    int broadcast = 1;
    if (setsockopt(sfd,SOL_SOCKET,SO_BROADCAST,&broadcast,sizeof(int))<0)
    {
        ERR_MSG("setsockopt");
        return -1;
    }
    

    //2. bind 绑定，但是非必须绑定

    //3.填充接收方的地址信息结构体，供给sendto函数使用 
    //a. IP 填广播IP
    //b. PORT:与接收方绑定的端口号一致即可


    //4.sendto   发送数据


    //服务器自身的地址信息结构体，真实的地址信息结构体根据AF_INET查找
    //man 7 ip
    //供给sendto函数使用
    struct sockaddr_in cin;
    cin.sin_family = AF_INET;
    cin.sin_port = htons(PORT);
    cin.sin_addr.s_addr = inet_addr(IP);
    //2.绑定服务器的地址信息结构体  bind  绑定为非必须
    /*
    if(bind(sfd,(struct sockaddr *)&sin,sizeof(sin)) < 0)
    {
        ERR_MSG("bind");
        return -1;
    }
    printf("udp server bind success\n");
    */

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
        
    }
    

    //5.关闭套接字文件描述符
    close(sfd);



    return 0;
}
