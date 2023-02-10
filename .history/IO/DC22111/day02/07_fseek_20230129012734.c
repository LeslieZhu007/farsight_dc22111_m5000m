#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define ERR_MSG(msg) do\
{\
    fprintf(stderr,"line:%d\n",__LINE__);\
    perror(msg);\
} while (0);


int main(int argc, char const *argv[])
{
    //读写fseek.txt文件
    FILE *src_fp = fopen("fseek.txt","w+");
    if (NULL == src_fp)
    {
        ERR_MSG("src_fopen");
        return -1;
    }

    fput('a',src_fp);
    fput('b',src_fp);
    fput('c',src_fp);

    
    if (fclose(src_fp) < 0)
    {
        ERR_MSG("src_fclose");
        return -1;
    }
    

    return 0;
}
