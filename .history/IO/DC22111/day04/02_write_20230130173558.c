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
    //权限仅在O_CREAT有效的情况下才可以使用
    //如果open.txt已经存在，则后期修改的权限变更无效
    //将umask清零
    umask(0);
    int fd=open("open.txt",O_WRONLY|O_CREAT|O_TRUNC,0777);
    if (fd < 0)
    {
        ERR_MSG("open");
        return -1;
    }
    
    fprintf(stdout,"fd = %d\n",fd);

    //写入
    char buf[32] = "";
    fprintf(stdout,"请输入>>>");
    //fscanf(stdin,"%s",buf);  //不会拿空格 \n \t
    fgets(buf,sizeof(buf),stdin); //  \n 文件结尾  停止读取  ====> \n 会拿  空格 \t 也会拿 ==>自动补\0
    //不想要\n
    buf[strlen(buf)-1] = 0;  //'\0' //fgets会读取到'\n',将 '\n' 修改称 '\0'
    fprintf(stdout,"buf = %s\n",buf);



    ssize_t ret = write(fd,buf,strlen(buf));
    printf("ret = %ld\n",ret);






    if (close(fd) < 0)
    {
        ERR_MSG("close");
        return -1;
    }
    
    
    return 0;
}
