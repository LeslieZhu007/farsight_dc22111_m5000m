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
    printf("fopen succeed\n");


    char file_name[20];
    printf("输入您要拷贝到的文件的文件名:");
    scanf("%s",file_name);

    FILE *fp1 = fopen(file_name,"w");
    if(NULL == fp1)
    {
        perror("fopen");
        return -1;
    }
    printf("%s open succeed\n",file_name);



    




    return 0;
}
