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
char buf[128] = {0};

int main(int argc, char *argv[])
{
    int fd1,fd2,ret,epfd,i;
    fd_set rfds; //可读集合
    struct epoll_event event;
    struct epoll_event events[20];

    fd1 = open("/dev/mychrdev", O_RDWR);
    if (fd1 < 0)
    {
        printf("打开文件失败%d\n",__LINE__);
        exit(-1);
    }
    //创建epoll
    epfd = epoll_create(5);
    if (epfd < 0)
    {
        printf("创建epoll失败%d\n",__LINE__);
        return epfd;
    }

    //添加要监听的事件的文件描述符
    event.events=EPOLLIN;
    event.data.fd=fd1; //可以不填
    ret = epoll_ctl(epfd, EPOLL_CTL_ADD,fd1, &event);
    if (ret < 0)
    {
        printf("添加文件描述符失败\n");
        return ret;
    }
    while (1)
    {
        //阻塞等待事件发生
        ret = epoll_wait(epfd,events,20,-1);
        if (ret < 0)
        {
            printf("epoll_wait失败\n");
            return ret;
        }
        for (i=0;i<ret;i++)
        {
            if(events->events)
            read(events[i].data.fd,buf,sizeof(buf));
            printf("buf:%s\n",buf);
        }

    }

    return 0;
}

