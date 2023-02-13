#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    
    //创建报式套接字
    //1.创建宝石套接字   socket
    int sfd = socket(AF_INET,SOCK_DGRAM,0);
    if (sfd < 0)
    {
        ERR_MSG("socket");
        return -1;
    }

    //绑定，非必须绑定

    //发送下载请求给服务器，服务器IP widowsIP   port:69

    //循环接收数据包  recvfrom
    //回复应答包 sendto
    //知道数据大小小于 512字节，结束循环，下载完毕




    return 0;
}
