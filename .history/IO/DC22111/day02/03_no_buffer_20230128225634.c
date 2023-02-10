#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


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
