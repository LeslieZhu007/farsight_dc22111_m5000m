#include <stdio.h>


int main(int argc, char const *argv[])
{
    int file_size = 0;
    //打开fopen, r
    FILE *fp = fopen("./01_fopen.c","r");
    if(NULL == fp)
    {
        perror("fopen");
        return -1;
    }
    printf("01_fopen.c open succeed\n");

    /*************code logic begin****************/

    char c = 0;
    while (1)
    {
        c = fgetc(fp);
        if (EOF==c)
        {
            break;
        }
        file_size++;
    }
    
    printf("the size of 01_fopen.c is %d\n",file_size);

    /*************code logic end****************/
    if(fclose(fp) < 0)
    {
        perror("fclose");
        return -1;
    }
    printf("fp fclose succeed\n");

    return 0;
}
