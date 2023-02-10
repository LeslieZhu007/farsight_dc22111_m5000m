#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


#define ERR_MSG(msg) do\
{\
    fprintf(stderr,"line:%d\n",__LINE__);\
    perror(msg);\
} while (0);



int main(int argc, char const *argv[])
{
    //打开  读的方式
    int fd = open("sophie_marceau.jpeg",O_RDONLY);
    if (fd < 0)
    {
        ERR_MSG("open");
        return -1;
    }
    /****************main code begin*****************/



    
    /****************main code end*****************/
    if (close(fd) < 0)
    {
        ERR_MSG("close");
        return -1;
    }

    return 0;
}
