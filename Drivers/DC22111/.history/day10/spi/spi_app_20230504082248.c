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
char writebuf[2] = {0};
int main(int argc, char const *argv[])
{
    int tem,hum;
    float tem1,hum1;

    int fd = open("/dev/m74hc595_1",O_RDWR);
    if (fd < 0)
    {
        printf("设备文件打开失败\n");
        exit(-1);
    }
    
    while (1)
    {
        char num1[10];
        printf("请输入一个四位数:");
        fscanf(stdin, "%s", num1);
        while (getchar()!=10);
        for (int i = 0; i < 4; i++)
        {
            printf("num1[%d] = %d %c\n", i, num1[i], num1[i]);
            switch(num1[i])
            {
                case '0':
                {
                    writebuf[0] = sec[i];
                    writebuf[1] = num[0];
                }
                break;
                case '1':
                {
                    writebuf[0] = sec[i];
                    writebuf[1] = num[1];
                }
                break;
                case '2':
                {
                    writebuf[0] = sec[i];
                    writebuf[1] = num[2];
                }
                break;
                case '3':
                {
                    writebuf[0] = sec[i];
                    writebuf[1] = num[3];
                }
                break;
                case '4':
                {
                    writebuf[0] = sec[i];
                    writebuf[1] = num[4];
                }
                break;
                case '5':
                {
                    writebuf[0] = sec[i];
                    writebuf[1] = num[5];
                }
                break;
                case '6':
                {
                    writebuf[0] = sec[i];
                    writebuf[1] = num[6];
                }
                break;
                case '7':
                {
                    writebuf[0] = sec[i];
                    writebuf[1] = num[7];
                }
                break;
                case '8':
                {
                    writebuf[0] = sec[i];
                    writebuf[1] = num[8];
                }
                break;
                case '9':
                {
                    writebuf[0] = sec[i];
                    writebuf[1] = num[9];
                }
                break;
                default:
                break;
            }

            write(fd,writebuf,sizeof(writebuf));
        }
        
        //1 0x80 2 0x40 3 0x20 4 0x10
        
        
        sleep(1);
    }
    
    return 0;
}
