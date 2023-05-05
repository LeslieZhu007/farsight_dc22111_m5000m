#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
char buf[128] = {0};
void horse_led(int fd);
void telegram_beep(int fd);
int main(int argc, char *argv[])
{
    int fd = open("/dev/mychrdev",O_RDWR);
    if (fd < 0)
    {
        printf("open failed\n");
        exit(-1);
    }
    while (1)
    {
        read(fd,buf,sizeof(buf));
        printf("buf:%s\n",buf);
    }
    
    
    

    return 0;
}

