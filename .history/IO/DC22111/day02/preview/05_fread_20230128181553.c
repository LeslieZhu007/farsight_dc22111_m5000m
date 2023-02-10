#include <stdio.h>
#define ERR_MSG(msg) do\
{\
    printf("line:%d\n",__LINE__);\
    perror(msg);\
} while (0);

int main(int argc, char const *argv[])
{
    FILE *fp = fopen("./fputs.txt","w");
    if(NULL == fp)
    {
        ERR_MSG("fopen");
        return -1;
    }
    printf("fopen success\n");

    /*********code main body begin************/
    int arr[10] = {56, 89, 12, 90};
    size_t res = 0 ;
    res = fwrite(arr,sizeof(int),10,fp);
    printf("成功输出%ld个数据\n", res);
    /*********code main body end************/
    if (fclose(fp) <0 )
    {
        ERR_MSG("fclose");
        return -1;
    }
    printf("fclose success\n");
    return 0;
}
