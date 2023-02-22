#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    char buf[128] = {0};
    ssize_t ret = 0;

    //1.获取文件描述符的原有属性 flags
    int flags = fcntl(0,F_GETFL);
    //2.在原有属性上加上非阻塞属性
    flags |= O_NONBLOCK;
    //3.将修改后的属性，重新设置回文件描述符中
    fcntl(0,F_SETFL,flags);
    //将0号文件描述符改为非阻塞属性


    while (1)
    {
        ret = read(0,buf,sizeof(buf));
        printf("%ld:%s\n",ret,buf);
    }
    
    
    return 0;
}
