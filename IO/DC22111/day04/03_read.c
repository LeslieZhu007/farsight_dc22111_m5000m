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
        bzero(buf,sizeof(buf)); //=> 清空
        //ret = read(fd,buf,sizeof(buf)-1);   //%s必须遇到\0才能打出
        ret = read(fd,buf,sizeof(buf)); 
        if (0 == ret)
        {
            printf("文件读取完毕\n");
            break;
        } else if (ret < 0)
        {
            perror("read");
            return -1;
        }
        
        //当前代码无法使用printf打印，因为
        //%s的原理是从指定首地址开始打印
        //直到\0结束，但是read函数中填充的是
        //sizeof(buf)个，会导致buf字符数组中没有保留'\0'位置
        //所以%s会越出buf的内存空间，往后继续找'\0'位置，会导致
        //出现乱码或者段错误
        //如果想要用printf打印，则需要手动在
        //printf打印字符串，以及strlen都是按照\0来定结束的

        //fprintf(stdout,"%s",buf);

        //向终端输出数据，读取到多少个就输出多少个
        write(stdout->_fileno,buf,ret);
    }
    
    //关闭
     if (close(fd) < 0)
    {
        ERR_MSG("close");
        return -1;
    }
    return 0;
}
