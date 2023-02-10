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
    if (argc < 2)
    {
        fprintf(stderr,"请输入文件名，格式:%s %s",argv[0],argv[1]);
        return 0;
    }
    
    //打开  读的方式
    int fd = open("sophie_marceau.jpeg",O_RDONLY);
    if (fd < 0)
    {
        ERR_MSG("open");
        return -1;
    }
    int w_fd = open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,0664);
    if (w_fd < 0)
    {
        ERR_MSG("destfile open");
        return -1;
    }
    /****************main code begin*****************/
    fprintf(stdout,"dest pic name>>>");
    ssize_t ret;
    char buf[32] = {0};

    while ((ret = read(fd,buf,sizeof(buf)))>0)
    {
        //bzero(buf,sizeof(buf)); 
        write(w_fd,buf,ret);
        //
    }
    fprintf(stdout,"%s copy succeeded\n",argv[1]);


    
    /****************main code end*****************/
    if (close(fd) < 0)
    {
        ERR_MSG("close");
        return -1;
    }

     if (close(w_fd) < 0)
    {
        ERR_MSG("destfile close");
        return -1;
    }

    return 0;
}
