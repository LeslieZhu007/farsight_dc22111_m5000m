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
#include <time.h>


int main(int argc, char const *argv[])
{
    //广播的发送方流程 -->类似UDP的客户端
    //1.socket 创建报式套接字

    //setsockopt  设置允许广播，默认式不允许广播，所以要设置允许广播
    // level SOL_SOCKET  optname:  SO_BROADCAST

    //2. bind 绑定，但是非必须绑定

    //3.填充接收方的地址信息结构体，供给sendto函数使用 
    //a. IP 填广播IP
    //b. PORT:与接收方绑定的端口号一致即可


    //4.sendto   发送数据
    return 0;
}
