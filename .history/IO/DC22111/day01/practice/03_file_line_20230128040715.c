#include <stdio.h>

#define ERR_MSG(msg) do{\
    printf("line:%d\n",__LINE__);\
    perror(msg);\
    }while (0);

int main(int argc, char const *argv[])
{
    if (argc <= 1)
    {
        printf("请输入文件名,usage:%s filename\n",argv[0]);
        return -1;
    }
    
    int file_line = 0;
    //打开fopen, r
    //FILE *fp = fopen("./01_fopen.c","r");
    FILE *fp = fopen(argv[1],"r");
    if(NULL == fp)
    {
        ERR_MSG(argv[1]);
        return -1;
    }
    printf("%s open succeed\n",argv[1]);

    /*************code logic begin****************/
    char c = 0;
    while (1)
    {
        c = fgetc(fp);
        if (EOF==c)
        {
            break;
        }
        if ('\n' == c)
        {
            file_line++;
        }
        
        
    }
    
    //printf("the lines of 01_fopen.c is %d\n",file_line);
    
    printf("the lines of 01_file_copy.c is %d\n",file_line);
    /*************code logic end****************/
    if(fclose(fp) < 0)
    {
        perror("fclose");
        return -1;
    }
    printf("fp fclose succeed\n");

    return 0;
}
