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
    printf("hello world\n");

    fprintf(stdout,"%s\n","helloworld");

    fprintf(stdout,"hey man");
    
    return 0;
}
