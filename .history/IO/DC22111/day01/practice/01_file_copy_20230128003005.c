#include <stdio.h>


int main(int argc, char const *argv[])
{
    //打开fopen, r
    FILE *fp = fopen("./01_fopen.c","r");
    if(NULL == fp)
    {
        perror("fopen");
        return -1;
    }
    printf("01_fopen.c open succeed\n");


    char file_name[20];
    printf("输入您要拷贝到的文件的文件名:");
    scanf("%s",file_name);

    
    
    return 0;
}
