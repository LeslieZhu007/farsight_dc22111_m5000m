#include "command.h"


int main(int argc, char const *argv[])
{
    int fd0 = open("/dev/gpiochrdev0",O_RDWR);
    if (fd0 < 0)
    {
        printf("open failed\n");
        return -1;
    }

    int fd1 = open("/dev/gpiochrdev1",O_RDWR);
    if (fd1 < 0)
    {
        printf("open failed\n");
        return -1;
    }

    int fd2 = open("/dev/gpiochrdev2",O_RDWR);
    if (fd2 < 0)
    {
        printf("open failed\n");
        return -1;
    }

    


    return 0;
}
