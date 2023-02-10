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

void lines_calculation(FILE *src_fp,const char *filename)
{
    char str[32] = ""; //{'\0'} {0}
    int file_lines = 0;
    while (1)
    {
        if(fgets(str,sizeof(str),src_fp)==NULL)
        {
            break;
        }
        //判断读取的内容是否有\n 如果有则行数要++
        //由于fgets获取到\n后肯定会停止读取，并且停止读取后会自动补上\0
        //所以\n字符肯定在\0之前
        //所以只需要判断\0 之前是不是 \n 即可
        //即只需要找到最后一个位置，判断是否为 \n
        //字符串的最后一个位置的下标为 strlen(str)-1
        if ('\n' == str[strlen(str)-1])
        {
            file_lines++;
        }
    }
    fprintf(stdout,"file %s has %d lines\n",filename,file_lines);
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
    lines_calculation(src_fp,argv[1]);
    //修改
    fseek(src_fp,0,SEEK_SET); // ==  rewind(src_fp)
    size_calculation(src_fp,argv[1]);
    /***********main code end***************/
    if (fclose(src_fp) < 0)
    {
        ERR_MSG("src_fclose");
        return -1;
    }

    return 0;
}