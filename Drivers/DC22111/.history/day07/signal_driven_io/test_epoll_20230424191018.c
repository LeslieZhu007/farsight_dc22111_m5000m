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
#include <sys/epoll.h>
#include <signal.h>
char buf[128] = {0};
int fd1;
//定义信号处理函数
void sig_handler(int signo)
{
    read(fd1,buf,sizeof(buf));
    printf("buf:%s\n",buf);
}

int main(int argc, char *argv[])
{



    fd1 = open("/dev/mychrdev", O_RDWR);
    if (fd1 < 0)
    {
        printf("打开文件失败%d\n",__LINE__);
        exit(-1);
    }
    signal(SIGIO,sig_handler);
    fcntl(fd1,F_GETFL);



    while (1)
    {
        /* code */
    }
    
    
    return 0;
}

