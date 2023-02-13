#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    //1. 创建流式套接字
    int cfd = socket(AF_INET,SOCK_STREAM,0);
    if (cfd < 0)
    {
        /* code */
    }
    
    
    //2. 绑定科幻段自身的地址信息结构体---->非必须绑定

    //3. 连接服务器

    //4. 发送数据给服务器

    //5. 接收服务器返回的数据

    //6. 关闭文件描述符

    return 0;
}
