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

    

    return 0;
}
