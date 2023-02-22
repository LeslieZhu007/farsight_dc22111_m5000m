#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> 
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <wait.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct _info
{
    int newsockfd;
    struct sockaddr_in cin;

} INFO;

#define IP "192.168.8.249"
#define PORT 8888

void * callback (void *arg);

int deal_with_client(int newsockfd,struct sockaddr_in cin);

#define ERR_MSG(msg) do\
{\
   fprintf(stderr,"line:__%d__",__LINE__);\
   perror(msg);\
} while (0);


int main(int argc, char const *argv[])
{
    //1.socket
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    if (sockfd < 0)
    {
        ERR_MSG("socket");
        return -1;
    }
    
    //2.bind
    //bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
    struct sockaddr_in sin;
    sin.sin_family = AF_INET;;
    sin.sin_port = htons(PORT);
    sin.sin_addr.s_addr = inet_addr(IP);
    if (bind(sockfd,(struct sockaddr *)&sin,sizeof(sin)) < 0)
    {
        ERR_MSG("bind");
        return -1;
    }
    printf("bind success\n");

    //3.listen
    if (listen(sockfd,5) < 0)
    {
        ERR_MSG("listen");
        return -1;
    }
    printf("listen success\n");

    //4.accept
    // int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
    struct sockaddr_in cin;
    socklen_t addrlen = sizeof(cin);
    pid_t cpid = 0;

    pthread_t tid;

    while (1)
    {
        //主进程只用来接收请求
        int newsockfd = accept(sockfd,(struct sockaddr *)&cin,&addrlen);
        if ( newsockfd < 0)
        {
            ERR_MSG("accept");
            return -1;
        }
        printf("newsockfd = %d,accept success,the incoming ip==>%s,port==>%d\n", newsockfd,inet_ntoa(cin.sin_addr),htons(cin.sin_port));
        INFO info;
        info.cin = cin;
        info.newsockfd = newsockfd;
        //主线程接收到请求后创建子线程进行处理
        if (pthread_create(&tid,NULL,callback,(void *)&info)!=0)
        {
            ERR_MSG("pthread_create");
            break;
        }
    }
    pthread_detach(tid);
    close(sockfd);
    return 0;
}



void * callback (void *arg)
{
    INFO *info = (INFO *)arg;
    int newsockfd = info->newsockfd;
    struct sockaddr_in cin = info->cin;
    socklen_t addrlen = sizeof(cin);
    char buf[128] = {0};
    ssize_t ret = 0;

    while (1)
    {
        //接收之前先清0
        bzero(buf,sizeof(buf));
        //5.recv 
        //ssize_t recv(int sockfd, void *buf, size_t len, int flags);
        // recv(newsockfd, buf, sizeof(buf), 0) ==> read(newsockfd, buf, sizeof(buf))
        // recv(newsockfd, buf, sizeof(buf), 0) ==> recvfrom(newsockfd, buf, sizeof(buf), 0,NULL,NULL)
        ret = recv(newsockfd, buf, sizeof(buf), 0);
        if (ret < 0)
        {
            ERR_MSG("recv");
            break;
        } else if (0 == ret)
        {
            fprintf(stdout,"The remost host has shut down,ip==>%s,port==>%d\n",inet_ntoa(cin.sin_addr),htons(cin.sin_port));
            break;
        }
        printf("message received from %s:%d is %s\n",inet_ntoa(cin.sin_addr),\
        htons(cin.sin_port),buf);
        
        //6.send
        strcat(buf,"_Satoshi_Nakamoto\n");
        //ssize_t send(int sockfd, const void *buf, size_t len, int flags);
        //send(newsockfd,buf,sizeof(buf),0) = write(newsockfd,buf,sizeof(buf),0)
        //send(newsockfd,buf,sizeof(buf),0) =  sendto(newsockfd,buf,sizeof(buf),0, NULL, 0);
        ret = send(newsockfd,buf,sizeof(buf),0);
        if (ret < 0)
        {
            ERR_MSG("write");
            break;
        }
        printf("%ld bytes sent successfully\n",ret);
        
    }
    close(newsockfd);
    pthread_exit(NULL);
}
