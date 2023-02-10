#include <stdio.h>
#include <unistd.h>
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
    /*
    //由于操作系统优化，只打开文件不写的话，不会真正申请缓冲区
    char a = 'A';
    fputc(a,fp); 
    
    //计算全缓冲的大小:尾地址-首地址
    printf("%ld\n",fp->_IO_buf_end - fp->_IO_buf_base);
    */
    int i = 0;
    while (i < 4096+1)
    {
        fputc('a',fp); 
        i++;
    }
    
    while (1)
    {
        sleep(1);
    }
    


    fclose(fp);
    return 0;
}
