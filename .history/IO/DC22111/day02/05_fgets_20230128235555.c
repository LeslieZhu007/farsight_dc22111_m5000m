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
    FILE *fp = fopen("./fputs.txt","r");
    if (NULL == fp)
    {
        ERR_MSG("fopen");
        return -1;
    }

    /*************************/
    //从文件中读取字符串
   
    /*************************/
    if (fclose(fp) < 0)
    {
        ERR_MSG("fclose");
        return -1;
    }
    
    return 0;
}
