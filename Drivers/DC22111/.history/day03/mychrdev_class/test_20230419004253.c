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
int fd;
void horse_led();
int main(int argc, char *argv[])
{
    int fd = open("/dev/mychrdev",O_RDWR);
    if (fd < 0)
    {
        printf("open failed\n");
        return -1;
    }
    while (1)
    {
        printf("请输入两个字符:\n");
        printf("第一个字符:1(LED1),2(LED2),3(LED3)\n");
        printf("第二个字符:0(关灯),1(开灯)\n");
        fgets(buf,sizeof(buf),stdin);
        buf[strlen(buf)-1] = '\0'; //替换\n
        if (!strcmp(buf,"quit"))
        {
            break;
        }
        if (!strcmp(buf,"horse"))
        {
            horse_led();
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

void horse_led()
{
    while (1)
    {
    strcpy(buf,"11");
    write(fd,buf,sizeof(buf));
    sleep(0.2);
    strcpy(buf,"10");
    write(fd,buf,sizeof(buf));
    sleep(0.2);
    strcpy(buf,"21");
    write(fd,buf,sizeof(buf));
    sleep(0.2);
    strcpy(buf,"20");
    write(fd,buf,sizeof(buf));
    sleep(0.2);
    strcpy(buf,"31");
    write(fd,buf,sizeof(buf));
    sleep(0.2);
    strcpy(buf,"30");
    write(fd,buf,sizeof(buf));
    sleep(0.2);

    }
    
    
}