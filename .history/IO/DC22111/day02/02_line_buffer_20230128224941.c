#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define ERR_MSG(msg) do\
{\
    printf("line:%d\n",__LINE__);\
    perror(msg);\
} while (0);

int main(int argc, char const *argv[])
{
    /*
    printf("hello world\n");

    fprintf(stdout,"%s\n","helloworld");

    fprintf(stdout,"hey man\n");

    int a,b;
    scanf("%d",&a);
    printf("a = %d\n",a);

    fscanf(stdin,"%d",&b);
    fprintf(stdout,"b = %d\n",b);
*/
    //printf("aaaa\n");
    printf("aaaa");
    printf("%ld\n",stdout->_IO_buf_end - stdout->_IO_buf_base);//1024byte = 1kb
    printf("%ld\n",stdin->_IO_buf_end - stdin->_IO_buf_base);//1024byte = 1kb

    while (1)
    {
        sleep(1);
    }
    
    return 0;
}
