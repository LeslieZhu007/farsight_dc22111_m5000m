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

    int fd = open("/dev/si7006");
    if (fd < 0)
    {
        printf("设备文件打开失败\n");
        exit(-1);
    }
    
    while (1)
    {
        //循环获取数据





    }
    
    return 0;
}
