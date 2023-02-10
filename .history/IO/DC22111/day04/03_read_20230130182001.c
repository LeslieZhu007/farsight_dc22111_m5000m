#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


#define ERR_MSG(msg) do\
{\
    fprintf(stderr,"line:%d\n",__LINE__);\
    perror(msg);\
} while (0);


int main(int argc, char const *argv[])
{
    //打开  读的方式
    int fd = open("10_file_lines.txt",O_RDONLY);
    if (fd < 0)
    {
        ERR_MSG("open");
        return -1;
    }
    ssize_t ret;
    //读取数据
    char buf[32] = {0};
    /*
    ret = read(fd,buf,5);
    fprintf(stdout,"%ld %s\n",ret,buf); //5 hello

    ret = read(fd,buf,5);
    fprintf(stdout,"%ld %s\n",ret,buf); //5  worl

    ret = read(fd,buf,5);
    fprintf(stdout,"%ld %s\n",ret,buf); //5 d\nabc

    ret = read(fd,buf,5);
    fprintf(stdout,"%ld %s\n",ret,buf); //5 de\n12

    bzero(buf,sizeof(buf));
    ret = read(fd,buf,5);
    fprintf(stdout,"%ld %s\n",ret,buf); //3 34\n12 ==>12是上次读取的残值

     bzero(buf,sizeof(buf));
    ret = read(fd,buf,5);
    fprintf(stdout,"%ld %s\n",ret,buf);  // 0
*/

    while (1)
    {
        bzero(buf,sizeof(buf));
        ret = read(fd,buf,sizeof(buf)-1);
        if (0 == ret)
        {
            printf("文件读取完毕\n");
            break;
        } else if (ret < 0)
        {
            perror("read");
            return -1;
        }
        
        
        fprintf(stdout,"%s",buf);
    }
    
    //关闭
    return 0;
}
