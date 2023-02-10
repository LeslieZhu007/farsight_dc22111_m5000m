#include <stdio.h>
#define ERR_MSG(msg) do\
{\
    printf("line:%d\n",__LINE__);\
    perror(msg);\
} while (0);

int main(int argc, char const *argv[])
{
    //全缓冲
    FILE *fp = fopen("./fullbuffer.txt","w");
    if (NULL == fp)
    {
        ERR_MSG("fopen");
        return -1;
    }
    
    //计算全缓冲的大小:尾地址-首地址
    printf("%ld\n",fp->_IO_buf_end - fp->_IO_buf_base);
    fclose(fp);
    return 0;
}
