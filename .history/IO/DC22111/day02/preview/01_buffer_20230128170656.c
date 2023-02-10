#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    FILE *fp = fopen("./fputc.txt","w");
    if(NULL == fp)
    {
        perror("fopen");
        return -1;
    }

    //
    fputc('a',fp);
    fputc('b',fp);
    fputc('c',fp);

    printf("%ld\n",fp->_IO_buf_end - fp->_IO_buf_base);

    if(fclose(fp) < 0)
    {
        perror("fclose");
        return -1;
    }
    return 0;
    return 0;
}
