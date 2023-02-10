#include <stdio.h>
 #include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
  #include <netinet/in.h>
       #include <netinet/ip.h> /* superset of previous */

#define PORT 8888 //1024-49151
#define ERR_MSG(msg) do {\
    fprintf(stderr,"line: __%d__ ",__LINE__);\
    perror(msg);\
} while (0)

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
    //创建流式套接字  -->> TCP
    int sfd =  socket(AF_INET, SOCK_STREAM, 0);
    if (sfd < 0)
    {
        ERR_MSG("socket");
        return -1;
    }

    //填充地址信息结构体，真实的地址信息结构体在man 7 ip
    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORT); //1024~49151 网络字节序

    //功能
    int bind(sfd, const struct sockaddr *addr,socklen_t addrlen);
    
    return 0;
}
