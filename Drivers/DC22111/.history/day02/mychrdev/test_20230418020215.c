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
int main(int argc, char *argv[])
{
    int fd = open("/dev/mychrdev",O_RDWR);
    if (fd < 0)
    {
        printf("open failed\n");
        return -1;
    }
    while (!strcmp(fgets(buf,sizeof(buf),stdin),"quit"))
    {
        buf[strlen(buf)-1] = '\0'; //替换\n
        //向设备中写
        write(fd,buf,sizeof(buf));
        //从设备文件中读取
        memset(buf,0,sizeof(buf));
        read(fd,buf,sizeof(buf));

        printf("buf returned from kernel==>%s\n",buf);
    }
    
    
    

    return 0;
}