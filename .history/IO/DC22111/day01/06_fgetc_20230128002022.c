#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *fp = fopen("./fputc.txt","r");
    if(NULL == fp)
    {
        perror("fopen");
        return -1;
    }

    //
    char c=0;
    c = fgetc(fp);
    printf("%c = %c\n",c);

    if(fclose(fp) < 0)
    {
        perror("fclose");
        return -1;
    }
    return 0;
}
