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
    if (argc < 3)
    {
        fprintf(stderr,"请在命令行传入两个文件名，格式:%s 源文件名 目标文件名\n",argv[0]);
        return -1;
    }
    
    FILE *src_fp = fopen(argv[1],"r");
    if (NULL == src_fp)
    {
        ERR_MSG("src_fopen");
        return -1;
    }

    FILE *dest_fp = fopen(argv[2],"w");
    if (NULL == dest_fp)
    {
        ERR_MSG("dest_fopen");
        return -1;
    }
    /***********main code begin*************/
    char str[128] = ""; //{'\0'} {0}
    while (fgets(str,sizeof(str),src_fp)!=NULL)
    {
        fputs(str,dest_fp);
        bzero(str,sizeof(str));
    }
    
    /***********main code end***************/
    if (fclose(src_fp) < 0)
    {
        ERR_MSG("src_fclose");
        return -1;
    }

    if (fclose(dest_fp) < 0)
    {
        ERR_MSG("dest_fclose");
        return -1;
    }
    

    return 0;
}
