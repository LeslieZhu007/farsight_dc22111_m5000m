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
//定义功能码
#define LED_ON _IOW('l',1,int)
#define LED_FF _IOW('l',0,int)

int main(int argc, char *argv[])
{
    int fd = open("/dev/mychrdev",O_RDWR);
    if (fd < 0)
    {
        printf("open failed\n");
        return -1;
    }

    int a,b;
    while(1)
    {
        printf("请输入要实现的功能:1 开灯 0 关灯\n");
        fscanf(fd, "%d", &a);
        if(a==1)
        {
            printf("请输入要实现的功能:1(开灯)  0(关灯) >");
            scanf("%d", &b);
            ioctl(fd,LED_ON,&b);
        } else
        {
            printf("请输入要实现的功能:1(开灯)  0(关灯) >");
            scanf("%d", &b);
            ioctl(fd,LED_OFF,&b);
        }
    }



    /*
    while (1)
    {
        printf("请输入两个字符:\n");
        printf("第一个字符:1(LED1),2(LED2),3(LED3)\n");
        printf("第二个字符:0(关灯),2(开灯)\n");
        fgets(buf,sizeof(buf),stdin);
        buf[strlen(buf)-1] = '\0'; //替换\n
        if (!strcmp(buf,"quit"))
        {
            break;
        }
        //向设备中写
        write(fd,buf,sizeof(buf));
        //从设备文件中读取
        memset(buf,0,sizeof(buf));
        read(fd,buf,sizeof(buf));

        printf("buf returned from kernel==>%s\n",buf);
    }
    */
    
    

    return 0;
}