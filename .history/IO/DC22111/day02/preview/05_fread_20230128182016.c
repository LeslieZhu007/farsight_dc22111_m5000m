#include <stdio.h>
#define ERR_MSG(msg) do\
{\
    printf("line:%d\n",__LINE__);\
    perror(msg);\
} while (0);

int main(int argc, char const *argv[])
{
    FILE *fp = fopen("./fputs.txt","r");
    if(NULL == fp)
    {
        ERR_MSG("fopen");
        return -1;
    }
    printf("fopen success\n");

    /*********code main body begin************/
    int arr[10] = {0};
    size_t res = 0 ;
    res = fread(arr,sizeof(int),410,fp);
    printf("成功读取%ld个数据\n", res);
    for (int i = 0; i < 10; i++)
    {
        printf("arr[%d] = %d\n",i,arr[i]);
    }
    
    /*********code main body end************/
    if (fclose(fp) <0 )
    {
        ERR_MSG("fclose");
        return -1;
    }
    printf("fclose success\n");
    return 0;
}
