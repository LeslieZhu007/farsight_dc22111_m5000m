#include <stdio.h>


int main(int argc, char const *argv[])
{
    int file_line = 0;
    //打开fopen, r
    FILE *fp = fopen("./01_fopen.c","r");
    if(NULL == fp)
    {
        perror("fopen");
        return -1;
    }
    printf("01_fopen.c open succeed\n");

    char c = 0;
    while (1)
    {
        c = fgetc(fp);
        if ('\n'==c)
        {
            break;
        }
        file_line++;
    }
    
    printf("the size of 01_fopen.c is %d\n",file_line);

    return 0;
}
