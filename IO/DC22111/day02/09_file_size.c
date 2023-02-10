#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define ERR_MSG(msg) do\
{\
    fprintf(stderr,"line:%d\n",__LINE__);\
    perror(msg);\
} while (0);

void size_calculation(FILE *src_fp,const char *filename)
{
    char str[32] = ""; //{'\0'} {0}
    int file_size = 0;
    while (fgets(str,sizeof(str),src_fp)!=NULL)
    {
        file_size+=strlen(str);
    }
    fprintf(stdout,"file %s has %d bytes in size\n",filename,file_size);
}

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr,"请在命令行传入文件名，格式:%s 文件名\n",argv[0]);
        return -1;
    }
    
    FILE *src_fp = fopen(argv[1],"r");
    if (NULL == src_fp)
    {
        ERR_MSG("src_fopen");
        return -1;
    }

    /***********main code begin*************/
    size_calculation(src_fp,argv[1]);
    /***********main code end***************/
    if (fclose(src_fp) < 0)
    {
        ERR_MSG("src_fclose");
        return -1;
    }

    return 0;
}
