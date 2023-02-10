#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>


int main(int argc, char const *argv[])
{
    umask(0);
    if(mkfifo("myfifo",0777)<0)
    {
        printf("errno = %d\n",errno);
        //#define EEXITST 17 ==> 文件存在的错误排除
        if(17!=errno)
        {
            perror("mkfifo");
            return -1;
        }
        
    }
    printf("fifo create success\n");

    //只能用文件IO，不能用标准IO
    //int fd = open("myfifo",O_RDONLY);
    //int fd = open("myfifo",O_WRONLY);
    int fd = open("myfifo",O_RDWR);
    if(fd < 0)
    {
        perror("open");
        return -1;
    }

    printf("RDWR open myfifo success\n");



    return 0;
}
