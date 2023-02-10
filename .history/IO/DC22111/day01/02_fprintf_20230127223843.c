#include <stdio.h>

int main(int argc, char const *argv[])
{
    //打开fopen, w
    FILE *fp = fopen("./fprintf.txt","w");
    if(NULL == fp)
    {
        perror("fopen");
        return -1;
    }
    printf("fopen succeed\n");

    //向文件中写入数据
    fprintf(fp,"hello world %d\n",10);


    if(fclose(fp) < 0)
    {
        perror("fclose");
        return -1;
    }
    printf("fclose succeed\n");

    return 0;
}
