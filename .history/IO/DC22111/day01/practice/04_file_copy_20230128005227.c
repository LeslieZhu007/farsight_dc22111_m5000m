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





    return 0;
}
