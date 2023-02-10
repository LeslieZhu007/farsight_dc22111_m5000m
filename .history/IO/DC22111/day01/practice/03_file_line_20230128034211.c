#include <stdio.h>


int main(int argc, char const *argv[])
{
    if (argc < 0)
    {
        /* code */
    }
    
    int file_line = 0;
    //打开fopen, r
    //FILE *fp = fopen("./01_fopen.c","r");
    FILE *fp = fopen("./01_file_copy.c","r");
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
