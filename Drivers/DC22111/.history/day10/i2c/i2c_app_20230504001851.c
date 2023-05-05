#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>  
#include "iic.h"

int main(int argc, char const *argv[])
{
    int tem,hum;
    float tem1,hum1;

    int fd = open("/dev/si7006",O_RDWR);
    if (fd < 0)
    {
        printf("设备文件打开失败\n");
        exit(-1);
    }
    
    while (1)
    {
        //循环获取数据
        ioctl(fd,GET_HUM,hum);
        ioctl(fd,GET_TEM,tem);
        //大小端转换
        hum = ntohs(hum);
        tem = ntohs(tem);
        //计算数据
        



        sleep(1);
    }
    
    return 0;
}
