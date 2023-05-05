#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>  
//0 1 2 3 4 5 6 7 8 9
int num[10] = {0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE0,0xFE,0xF6};
// 1 2 3 4
int sec[4] = {0x80,0x40,0x20,0x10};
char writebuf[8]
int main(int argc, char const *argv[])
{
    int tem,hum;
    float tem1,hum1;

    int fd = open("/dev/m74hc595",O_RDWR);
    if (fd < 0)
    {
        printf("设备文件打开失败\n");
        exit(-1);
    }
    
    while (1)
    {
        char num[4];
        printf("请输入一个四位数:");
        fscanf(stdin, "%s", num);
        while (getchar()!=10);
        for (int i = 0; i < 4; i++)
        {
            switch(num[i])
            {
                case 0:
                {

                }
                break;
            }
        }
        
        //1 0x80 2 0x40 3 0x20 4 0x10
        
        
        sleep(1);
    }
    
    return 0;
}
