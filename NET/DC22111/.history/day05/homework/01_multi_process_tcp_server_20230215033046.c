#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> 
#include <arpa/inet.h>

#define IP "192.168.8.249"
#define PORT 8888

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
    int newsockfd = accept(sockfd,(struct sockaddr *)&cin,&addrlen);
    if ( newsockfd < 0)
    {
        ERR_MSG("accept");
        return -1;
    }
    printf("accept success,the incoming ip==>%s,port==>%d\n",inet_ntoa(cin.sin_addr),htons(cin.sin_port));

    
    while (1)
    {
        //5.receive

        //6.send
    }
    
    return 0;
}