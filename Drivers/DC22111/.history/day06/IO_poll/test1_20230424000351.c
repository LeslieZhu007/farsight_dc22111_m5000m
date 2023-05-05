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
    int fd1,fd2,ret;
    fd_set rfds; //可读集合

    fd1 = open("/dev/mychrdev", O_RDWR);
    if (fd1 < 0)
    {
        printf("打开文件失败%d\n",__LINE__);
        exit(-1);
    }
    
    fd2 = open("/dev/input/mouse0", O_RDWR);
    if (fd2 < 0)
    {
        printf("打开文件失败%d\n",__LINE__);
        exit(-1);
    }
    
    //清空集合
    FD_ZERO(&rfds);
    FD_SET(fd1, &rfds);
    FD_SET(fd2, &rfds);
    ret = select(fd2+1, &rfds, NULL, NULL, NULL);
    if (ret < 0)
    {
        printf("select失败%d\n",__LINE__);
        exit(-1);
    }

        
    if (FD_ISSET(fd1, &rfds))
    {
        read(fd1, buf, sizeof(buf));
        printf("自定义设备时间发生 buf:%s\n", buf);
    }
    if (FD_ISSET(fd2, &rfds))
    {
        read(fd2, buf, sizeof(buf));
        printf("鼠标事件发生 buf:%s\n", buf);
    }
   
    
    
    close(fd1);
    close(fd2);

    return 0;
}

