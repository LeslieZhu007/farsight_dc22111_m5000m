#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define ERR_MSG(msg) do\
{\
    fprintf(stderr,"line:%d\n",__LINE__);\
    perror(msg);\
} while (0);


int main(int argc, char const *argv[])
{
    //权限仅在O_CREAT有效的情况下才可以使用
    //如果open.txt已经存在，则后期修改的权限变更无效

    //根据man手册中
    //the mode of the created file is (mode & ~umask).
    //S_IRWXU|S_IRWXG|S_IRWXO ==>0777 | ~(002)
    //==> 0777| 0 775 ==> 0775
    //可知，在不修改umask值的情况下创建文件的最大权限为0775
    //要得到0777,则需要修改umask值为0
    umask(0);
    int fd=open("open.txt",O_WRONLY|O_CREAT|O_TRUNC,S_IRWXU|S_IRWXG|S_IRWXO);
    if (fd < 0)
    {
        ERR_MSG("open");
        return -1;
    }
    
    fprintf(stdout,"fd = %d\n",fd);
    
    return 0;
}
