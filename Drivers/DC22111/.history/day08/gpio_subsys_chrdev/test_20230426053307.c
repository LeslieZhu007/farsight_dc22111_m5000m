#include "command.h"


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




    return 0;
}
