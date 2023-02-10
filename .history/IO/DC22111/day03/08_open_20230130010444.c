#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define ERR_MSG(msg) do\
{\
    fprintf(stderr,"line:%d\n",__LINE__);\
    perror(msg);\
} while (0);


int main(int argc, char const *argv[])
{
    int fd=open("open.txt",O_WRONLY|O_CREAT|O_TRUNC);
    if (fd < 0)
    {
        ERR_MSG("open");
        return -1;
    }
    
    fprintf(stdout,"fd = %d\n",fd);
    
    return 0;
}
