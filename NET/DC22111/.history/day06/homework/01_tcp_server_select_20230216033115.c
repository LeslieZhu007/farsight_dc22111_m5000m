#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

#define PORT 8888 //1024-49151
#define IP "192.168.8.249"  //ifconfig
#define ERR_MSG(msg) do {\
    fprintf(stderr,"line: __%d__ ",__LINE__);\
    perror(msg);\
} while (0)


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

    //accept:阻塞函数，阻塞等待客户端连接成功
             //当客户端连接成功后,会从已完成连接的队列头中获取一个客户端信息
             //并生成一个新的文件描述符
             //注意: 新生成的文件描述符才是用于通信的文件描述符
    struct sockaddr_in cin; //存储客户端的地址信息
    socklen_t addrlen = sizeof(cin);
    int newfd = 0;
    int select_ret = 0;
    int maxfd = 0;
    fd_set readfds,tempfds;
    char buf[128] = "";
    ssize_t  ret = 0;



    FD_ZERO(&readfds);
    FD_ZERO(&tempfds);
    //监听输入端和sfd
    FD_SET(0,&readfds);
    FD_SET(sfd,&readfds);


    while (1)
    {
        select_ret =  select(maxfd+1, &tempfds, NULL,NULL, NULL);
        if (select_ret < 0)
        {
            ERR_MSG("select");
            break;
        } else if (0==select_ret)
        {
            printf("time out .........\n");
        }
        //select语句执行成功

        for (int i = 0; i <=maxfd; i++)
        {
            if (!FD_ISSET(i,&tempfds))
            {
                continue;
            }
            //进入匹配模式
            if (0==i)
            {
                printf("键盘输入事件.....\n");
                fgets(buf,sizeof(buf),stdin);
                buf[strlen(buf)-1] = 0;
                printf("键盘输入事件,buf=%s\n",buf);

            } else if (sfd == i)
            {
                printf("accept事件....");
                newfd =  accept(sfd,(struct sockaddr *)&cin,&addrlen);
                if (newfd < 0)
                {
                    ERR_MSG("accept");
                    return -1;
                }
                printf("[%s | %d] newfd = %d\n",inet_ntoa(cin.sin_addr),ntohs(cin.sin_port),newfd);

                //将newfd添加到集合中
                FD_SET(newfd,&readfds);

                maxfd = maxfd>newfd?maxfd:newfd;
            } else
            {
                printf("触发客户端交互事件............\n");
                bzero(buf,sizeof(buf));
                ret = recv(i,buf,sizeof(buf),0);
                if (ret < 0)
                {
                    ERR_MSG("recv");
                    return -1;
                } else if (0 == ret)
                {
                    printf("[%s | %d] newfd = %d 客户端断开连接\n",inet_ntoa(cin.sin_addr),ntohs(cin.sin_port),newfd);
                    //断开连接需关闭文件描述符
                    close(i);
                    //从readfds中剔除
                    FD_CLR(i,&readfds);
                    //更新maxfd;
                    maxfd = update_maxfd(maxfd,readfds);
                }
                
                printf("%ld: %s\n",ret,buf);

                //TODO 发送 ----> 谁发给我数据，就发还给谁
                //ssize_t send(int sockfd, const void *buf, size_t len, int flags);
                strcat(buf,"*_*");
                if (send(i,buf,sizeof(buf),0) < 0)
                {
                    ERR_MSG("send");
                    continue;;
                }
                printf("send success\n");
            }
        }   
    }

    close(sfd);
    return 0;
}


int update_maxfd(int maxfd,fd_set readfds)
{
    for (int i = maxfd; i >= 0; i--)
    {
        if (FD_ISSET(i,&readfds))
        {
            return i;
        }
    }
}
