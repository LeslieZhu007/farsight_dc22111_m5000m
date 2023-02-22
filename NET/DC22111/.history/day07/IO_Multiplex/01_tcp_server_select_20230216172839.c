#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>

#define PORT 8888 //1024-49151
#define IP "192.168.8.249"  //ifconfig
#define ERR_MSG(msg) do {\
    fprintf(stderr,"line: __%d__ ",__LINE__);\
    perror(msg);\
} while (0)

int updateMaxfd(int maxfd,fd_set readfds);


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

    struct sockaddr_in save_cin[1024-4];//存储客户端的地址信息数组  //0，1，2，sfd不会有对应的客户端，所以减四
    struct sockaddr_in cin; //存储客户端的地址信息
    socklen_t addrlen = sizeof(cin);
    int newfd = 0;
    char buf[128] = "";
    ssize_t  ret = 0;
    int select_ret = 0;

    //设置一个读集合

    fd_set readfds,tempfds;
    //清空
    FD_ZERO(&readfds);
    FD_ZERO(&tempfds);

    //将需要监控的文件描述符加入到集合中
    FD_SET(0,&readfds);
    FD_SET(sfd,&readfds);

    int maxfd = sfd;

    struct timeval tm  = {0};

    //使用select
    while (1)
    {
        tm.tv_sec = 3;
        tm.tv_usec = 0;
        tempfds = readfds;
        select_ret =  select(maxfd+1,&tempfds,NULL,NULL, &tm);
        if (select_ret < 0)
        {
            ERR_MSG("select");
            return -1;
        } else if(0==select_ret)
        {
            printf("time out..........\n");
            break;
        }

        printf("line = %d\n",__LINE__);

        //能允许到当前位置，则代表集合中有文件描述符准备就绪
        //判断哪个文件描述符准备就绪，走对应的函数
        //select函数解除阻塞后，集合中会只剩下产生事件的文件描述符
        //例如: 0产生事件，则只剩下0
        //      sfd产生事件，则只剩下sfd
        //      0,sfd产生事件，则只剩下 0,sfd
        //判断集合中剩下哪个文件描述符，走对应函数即可

        for (int i = 0; i <= maxfd; i++)
        {
            if (FD_ISSET(i,&tempfds) == 0)
            {
                continue;
            }
            //能运行到这个位置，则说明i代表的文件描述符在tempfds中
            //即i代表的文件描述符触发事件
            if (0 == i)
            {
                //触发键盘输入事件 fgets
                fgets(buf,sizeof(buf),stdin);
                buf[strlen(buf)-1] = 0;
                printf("触发键盘输入事件:%s\n",buf);
            } else if(sfd == i)
            {
                //触发客户端连接事件 accept
                printf("触发客户端连接事件");
                //accept:阻塞函数，阻塞等待客户端连接成功
                //当客户端连接成功后,会从已完成连接的队列头中获取一个客户端信息
                //并生成一个新的文件描述符
                //注意: 新生成的文件描述符才是用于通信的文件描述符
        
                newfd =  accept(sfd,(struct sockaddr *)&cin,&addrlen);
                if (newfd < 0)
                {
                    ERR_MSG("accept");
                    return -1;
                }
                printf("[%s | %d] newfd = %d\n",inet_ntoa(cin.sin_addr),ntohs(cin.sin_port),newfd);

                save_cin[newfd-4] = cin;

                //将newfd添加到读集合中
                FD_SET(newfd,&readfds);
                //更新maxfd,判断newfd和maxfd谁大则最终maxfd就等于谁
                maxfd = maxfd>newfd? maxfd:newfd;
            } else
            {
                printf("触发客户端交互事件\n");
                //接收
                bzero(buf,sizeof(buf));
                ret = recv(i,buf,sizeof(buf),0); //此处要将newfd改为i
                if (ret < 0)
                {
                    ERR_MSG("recv");
                    break;
                } else if (0 == ret)
                {
                    printf("[%s | %d] newfd = %d 客户端断开连接\n",inet_ntoa(save_cin[i-4].sin_addr),ntohs(save_cin[i-4].sin_port),newfd);
                    //关闭文件描述符
                    close(i);

                    //从集合中剔除文件描述符
                    FD_CLR(i,&readfds);

                    //更新maxfd
                    maxfd = updateMaxfd(maxfd,readfds);
                } else
                {
                    printf("[%s | %d] newfd=%d : %s\n", 
							inet_ntoa(save_cin[i-4].sin_addr), ntohs(save_cin[i-4].sin_port), i, buf);
                }

                //谁发给我，拼接后还发给谁
                strcat(buf,"*_*");
                if (send(i,buf,sizeof(buf),0) < 0)
                {
                    ERR_MSG("send");
                    continue;
                }
                printf("send succcess __%d__\n",__LINE__);
                
            }
        }  
    }
    
    close(sfd);
    
    return 0;
}

int updateMaxfd(int maxfd,fd_set readfds)
{
    for (int i = maxfd; i > 0; i--)
    {
        if (FD_ISSET(i,&readfds))
        {
            return i;
        }  
    }
    return -1;
}
