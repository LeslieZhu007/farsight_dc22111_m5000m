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

    FILE *fp1 = fopen(file_name,"w");
    if(NULL == fp1)
    {
        perror("fopen");
        return -1;
    }
    printf("%s open succeed\n",file_name);

    /*************code logic begin****************/
    char c = 0;
    while (1)
    {
        c = fgetc(fp);
        if (EOF == c)
        {
            break;
        }
        
        fputc(c,fp1);
        
    }
    
    /*************code logic end****************/

    if(fclose(fp) < 0)
    {
        perror("fclose");
        return -1;
    }
    printf("fp fclose succeed\n");


    if(fclose(fp1) < 0)
    {
        perror("fclose");
        return -1;
    }
    printf("fp1 fclose succeed\n");

    
    
    return 0;
}
