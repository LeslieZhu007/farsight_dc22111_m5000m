#include "command.h"
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

int main(int argc, char const *argv[])
{
    int fd0 = open("/dev/gpiochrdev0",O_RDWR);
    if (fd0 < 0)
    {
        printf("LED1 open failed\n");
        return -1;
    }

    int fd1 = open("/dev/gpiochrdev1",O_RDWR);
    if (fd1 < 0)
    {
        printf("LED2 failed\n");
        return -1;
    }

    int fd2 = open("/dev/gpiochrdev2",O_RDWR);
    if (fd2 < 0)
    {
        printf("LED3 failed\n");
        return -1;
    }

    int a,b;
    while(1)
    {
        printf("请输入要实现的功能：1（开灯） 0（关灯）>\n");
        fscanf(stdin, "%d", &a);
        if(1==a) //开灯
        {
            printf("请输入要操作的灯: 1(LED1),2(LED2),3(LED3)>");
            scanf("%d", &b);
            if(1==b)
            {
                ioctl(fd0,LED1_ON,&b);
            }
            if(2==b)
            {
                ioctl(fd1,LED2_ON,&b);
            }
            if(3==b)
            {
                ioctl(fd2,LED3_ON,&b);
            }
            
        } else if(0==a) //关灯
        {
            printf("请输入要操作的灯: 1(LED1),2(LED2),3(LED3)>");
            scanf("%d", &b);
            if(1==b)
            {
                ioctl(fd0,LED1_OFF,&b);
            }
            if(2==b)
            {
                ioctl(fd1,LED2_OFF,&b);
            }
            if(3==b)
            {
                ioctl(fd2,LED3_OFF,&b);
            }
        }
    }




    return 0;
}
