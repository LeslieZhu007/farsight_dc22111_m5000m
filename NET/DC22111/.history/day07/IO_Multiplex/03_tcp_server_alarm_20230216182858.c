#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#define PORT 8888 //1024-49151
#define IP "192.168.8.249"  //ifconfig
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

//int sigaction(int signum, const struct sigaction *act,  //新的 行为
//                     struct sigaction *oldact);    // 旧的行为

void handler(int sig)
{
    printf("sig = %d\n",sig);

}

int main(int argc, char const *argv[])
{
    /*
    //捕获14号信号
    __sighandler_t s = signal(SIGALRM,handler);
    if(SIG_ERR == s)
    {
        ERR_MSG("signal");
        return -1;
    }
    */


    //socket  创建流式套接字  -->> TCP
    int sfd =  socket(AF_INET, SOCK_STREAM, 0);
    if (sfd < 0)
    {
        ERR_MSG("socket");
        return -1;
    }

    printf("sfd = %d\n",sfd);

    //允许端口快速被服用
    int reuse = 1;
    if(setsockopt(sfd,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(reuse)) < 0)
    {
        ERR_MSG("setsockopt");
        return -1;
    }
    

    //填充地址信息结构体，真实的地址信息结构体在man 7 ip
    //AF_INET --> man 7 ip
    struct sockaddr_in sin;
    sin.sin_family = AF_INET;   //必须要填AF_INET
    sin.sin_port = htons(PORT); //1024~49151 网络字节序
    sin.sin_addr.s_addr = inet_addr(IP);  //本机IP

    //bind: 功能 将IP地址和端口号绑定到指定套接字中
    if(bind(sfd, (const struct sockaddr *)&sin,sizeof(sin)) < 0)
    {
        ERR_MSG("bind");
        return -1;
    }
    printf("bind success __%d__\n",__LINE__);

    //listen: 将套接字设置为被动监听状态，只负责监听是否有客户端连接成功
    if(listen(sfd,10) <0)
    {
        ERR_MSG("listen");
        return -1;
    }
    printf("listen success __%d__\n",__LINE__);

    //accept:阻塞函数，阻塞等待客户端连接成功
             //当客户端连接成功后,会从已完成连接的队列头中获取一个客户端信息
             //并生成一个新的文件描述符
             //注意: 新生成的文件描述符才是用于通信的文件描述符
    struct sockaddr_in cin; //存储客户端的地址信息
    socklen_t addrlen = sizeof(cin);
    int newfd = 0;

    //1.获取信号的原有属性 flags
    struct sigaction act;
    sigaction(14,NULL,&act);

    //2.将flags中的信号自重启属性取消: flags &= (~信号自重启属性标志)
    act.sa_flags &= (~SA_RESTART);
    act.sa_handler = handler;  //为信号注册新的处理函数

    //3. 将修改后的flags重新设置回信号中
    sigaction(14,NULL,&act);

    alarm(3);


    newfd =  accept(sfd,(struct sockaddr *)&cin,&addrlen);
    if (newfd < 0)
    {
        ERR_MSG("accept");
        return -1;
    }
    printf("[%s | %d] newfd = %d\n",inet_ntoa(cin.sin_addr),ntohs(cin.sin_port),newfd);


    //通过文件描述符，读取数据
    //原型 ssize_t recv(int sockfd, void *buf, size_t len, int flags);
    char buf[128] = "";
    ssize_t  ret = 0;
    while (1)
    {
        bzero(buf,sizeof(buf));
        ret = recv(newfd,buf,sizeof(buf),0);
        if (ret < 0)
        {
            ERR_MSG("recv");
            break;
        } else if (0 == ret)
        {
            printf("[%s | %d] newfd = %d 客户端断开连接\n",inet_ntoa(cin.sin_addr),ntohs(cin.sin_port),newfd);
            break;
        }
        
        printf("%ld: %s\n",ret,buf);

        //TODO 发送 ----> 谁发给我数据，就发还给谁
        //ssize_t send(int sockfd, const void *buf, size_t len, int flags);
        strcat(buf,"*_*");
        if (send(newfd,buf,sizeof(buf),0) < 0)
        {
            ERR_MSG("send");
            return -1;
        }
        printf("send success\n");
        
    }
    
    close(newfd);
    close(sfd);
    
    return 0;
}
