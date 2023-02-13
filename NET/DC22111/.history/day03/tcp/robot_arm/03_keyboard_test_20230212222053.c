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

#define SER_PORT 7777 //1024-49151
#define SER_IP "192.168.8.177"  //ifconfig

#define CLI_PORT 4444   //客户端需要绑定的端口号
#define CLI_IP "192.168.8.177"

#define ERR_MSG(msg) do {\
    fprintf(stderr,"line: __%d__ ",__LINE__);\
    perror(msg);\
} while (0)

int main(int argc, char const *argv[])
{
    

    //打开键盘设备驱动文件 ----> /dev/input/event1
    int fd = open("/dev/input/event1",O_RDONLY);
    if (fd < 0)
    {
        ERR_MSG("send");
        return -1;
    }
    /*
    struct input_event {                              
     struct timeval time;
      __u16 type;
      __u16 code;
     __s32 value;
    };
    */
   struct input_event ev;

    while (1)
    {
        if(read(fd,&ev,sizeof(ev)) < 0)
        {
            ERR_MSG("read");
            return -1;
        }

        printf("type=%-4u code=%-4u value=%-4d \n",ev.type,ev.code,ev.value);
    }
 

    return 0;
}
