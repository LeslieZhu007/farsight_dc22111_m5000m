#include "dictionary.h"





int main(int argc, char const *argv[])
{
    //抽取函数
    /*******************连接服务器部分 begin***************************/
    //1. 创建流式套接字
    int cfd = socket(AF_INET,SOCK_STREAM,0);
    if (cfd < 0)
    {
        ERR_MSG("socket");
        return -1;
    }
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
/*******************连接服务器部分 end***************************/





    return 0;
}
