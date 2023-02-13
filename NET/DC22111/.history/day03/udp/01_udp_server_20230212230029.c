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

int main(int argc, char const *argv[])
{
    //1.创建宝石套接字   socket
    int sfd = socket(AF_INET,SOCK_DGRAM,0)

    //2.绑定服务器的地址信息结构体  bind

    while (1)
    {
        //3.接收客户端发送过来的数据


        //4.将数据发送给客户端
    }
    

    //5.关闭套接字文件描述符


    return 0;
}
