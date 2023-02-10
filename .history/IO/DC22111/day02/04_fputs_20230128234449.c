#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//此处参数msg如果写成整数，则在编译的过程中会报错，但是展开的过程中不会报错
#define ERR_MSG(msg) do\
{\
    fprintf(stderr,"line:%d\n",__LINE__);\
    perror(msg);\
} while (0);

int main(int argc, char const *argv[])
{
    fprintf(stderr,"hello world");
    perror("aaaa");
    while(1)
    {
        sleep(1);
    }
    return 0;
}
