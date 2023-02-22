#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    char buf[128] = {0};
    ssize_t ret = 0;


    //将0号文件描述符改为非阻塞属性


    while (1)
    {
        ret = read(0,buf,sizeof(buf));
        printf("%ld:%s\n",ret,buf);
    }
    
    
    return 0;
}
