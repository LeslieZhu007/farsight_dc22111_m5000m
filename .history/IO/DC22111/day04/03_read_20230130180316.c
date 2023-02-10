#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    //打开  读的方式
    int fd = open("open.txt",O_RDONLY);

    //读取数据


    //关闭
    return 0;
}
