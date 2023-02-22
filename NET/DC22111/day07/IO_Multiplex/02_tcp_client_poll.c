#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <poll.h>

#define SER_PORT 8888 //1024-49151
#define SER_IP "192.168.8.249"  //ifconfig
#define ERR_MSG(msg) do {\
    fprintf(stderr,"line: __%d__ ",__LINE__);\
    perror(msg);\
} while (0)

int main(int argc, char const *argv[])
{
    //1. 创建流式套接字
    int cfd = socket(AF_INET,SOCK_STREAM,3000); //设置超时时间为3s
    if (cfd < 0)
    {
        ERR_MSG("socket");
        return -1;
    }
    
    
    //2. 绑定科幻段自身的地址信息结构体---->非必须绑定,可以选择不绑
    //如果选择不绑定，则操作系统会默认绑定一个端口号给这个客户端



    //填充要连接的服务器的ip和端口
    struct sockaddr_in sin;
    sin.sin_family = AF_INET; //必须填AF_INET
    sin.sin_port = htons(SER_PORT); //服务器绑定的端口号
    sin.sin_addr.s_addr = inet_addr(SER_IP); //服务器绑定的IP
    //3. 连接服务器   int connect(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
    
    if(connect(cfd,(struct sockaddr *)&sin,sizeof(sin)) < 0)
    {
        ERR_MSG("connect");
        return -1;
    }

    printf("connect success\n");

    char buf[128];
    ssize_t ret = 0;
    //指定要监测的文件描述符集合
    struct pollfd fds[2] = {0};
    fds[0].fd = 0;
    fds[0].events = POLLIN;   //监测0号文件的读事件
    fds[1].fd = cfd;
    fds[1].events = POLLIN;   //监测fd文件的读事件

    int p_ret = 0;
    while (1)
    {
        p_ret =  poll(fds, 2, -1);
        if (p_ret < 0)
        {
            ERR_MSG("poll");
            return -1;
        }
        else if(0 == p_ret)
        {
            printf("time out ......\n");
            break;;
        }

        //能运行到当前位置，则代表集合中有文件描述符触发的事件
        //需要判断集合中的文件描述符的revents中有没有POLLIN;
        if(fds[0].revents & POLLIN)
        {
            //触发键盘输入事件
            //4. 发送数据给服务器.收多少 ，发多少字节
            bzero(buf,sizeof(buf));
            printf("请输入>>>");
            fgets(buf,sizeof(buf),stdin);
            buf[strlen(buf)-1] = 0; 
            // ssize_t send(int sockfd, const void *buf, size_t len, int flags);
            if(send(cfd,buf,sizeof(buf),0) < 0)
            {
                ERR_MSG("send");
                return -1;
            }
            printf("send success\n");

        }

        if(fds[1].revents & POLLIN)
        {
            //5. 接收服务器返回的数据
            bzero(buf,sizeof(buf));
            ret = recv(cfd,buf,sizeof(buf),0);
            if (ret < 0)
            {
                ERR_MSG("recv");
                return -1;
            } else if(0==ret)   //和管道性质一样，写端关闭，读完直接结束，返回0
            {
                printf("服务器端关闭\n");
                break;
            }
            printf(":%s\n",buf);
        }
    }
    //6. 关闭文件描述符
    close(cfd);

    return 0;
}
