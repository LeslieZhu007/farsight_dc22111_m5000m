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
        if (EOF==c)
        {
            break;
        }
        if ('\n' == c)
        {
            file_line++;
        }
        
        
    }
    
    printf("the lines of 01_fopen.c is %d\n",file_line);

    return 0;
}
