#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define IP "192.168.8.189"
int main(int argc, char const *argv[])
{
    /*
    typedef uint32_t in_addr_t;

    struct in_addr {
        in_addr_t s_addr;
    };
    */
    struct in_addr inp;
    
    int ret = inet_aton(IP, &inp);
    printf("IP = %#x\n",inp.s_addr);
    
    return 0;
}
