#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{
    char buf[128] = "";
    ssize_t ret = 0;
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
    int fd = open("myfifo",O_WRONLY);
    if(fd < 0)
    {
        perror("open");
        return -1;
    }
    printf("WRONLY open myfifo success\n");
    /*******************************************/
    if(mkfifo("myfifo1",0777)<0)
    {
        printf("errno = %d\n",errno);
        //#define EEXITST 17 ==> 文件存在的错误排除
        if(17!=errno)
        {
            perror("mkfifo1");
            return -1;
        }
        
    }
    printf("fifo1 create success\n");

    //只能用文件IO，不能用标准IO
    int fd1 = open("myfifo1",O_RDONLY);
    if(fd1 < 0)
    {
        perror("open");
        return -1;
    }
    printf("RDONLY open myfifo1 success\n");

    /*********************************************/
    //myfifo发送数据
    while (1)
    {
//myfifo1读取数据
        bzero(buf,sizeof(buf));
        ret = read(fd1,buf,sizeof(buf));
        if(ret < 0)
        {
            perror("read");
            return -1;
        } else if(0==ret)
        {
            fprintf(stderr,"对方进程退出\n");
            break;
        }
        printf("B==>收到 [%ld] : %s\n",ret,buf);
        if(strcasecmp(buf,"quit")==0)
        {
            break;
        }
        /************/
        bzero(buf,sizeof(buf));
        printf("B请输入>>>");
        fgets(buf,sizeof(buf),stdin);
        buf[strlen(buf)-1] = 0;

        if (write(fd,buf,sizeof(buf))<0)
        {
            perror("write");
            return -1;
        }

        printf("B发出 %s 成功\n",buf);
        if(strcasecmp(buf,"quit")==0)
        {
            break;
        } 
        
    }
    close(fd);
    close(fd1);
    return 0;
}
