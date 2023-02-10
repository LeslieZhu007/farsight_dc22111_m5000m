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

    fputc('a',src_fp);
    fputc('b',src_fp);
    fputc('c',src_fp);

    fclose(src_fp);

    //读取文件数据

    FILE *src_fp1 = fopen("fseek.txt","r");
    if (NULL == src_fp1)
    {
        ERR_MSG("src1_fopen");
        return -1;
    }
    char c = 0;
    c = fgetc(src_fp);
    fprintf(stdout,"%c %d\n",c,c);

    
    if (fclose(src_fp) < 0)
    {
        ERR_MSG("src_fclose");
        return -1;
    }
    

    return 0;
}
