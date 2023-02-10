#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char const *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr,"请输入两个文件名，源文件在前，目标文件在后\n");
        return -1;
    }
    
    int fd_src = open(argv[1],O_RDONLY);
    if (fd_src < 0)
    {
        perror("src open");
        return -1;
    }

    int fd_dest = open(argv[2],O_RDONLY);
    if (fd_dest < 0)
    {
        perror("dest open");
        return -1;
    }

    /******************main code begin********************/
    //求文件大小
    off_t file_size = lseek(fd_src,0,SEEK_END);
    pid_t pid = fork();
  
    if (pid > 0)
    {
        //父进程中 拷贝图片前半部分
        if (write(fd,"a",1) < 0)
        {
            perror("write");
            return -1;
        }

        printf("parent %ld\n",lseek(fd,0,SEEK_CUR));
        
    } else if(0 == pid)
    {
        sleep(1); //确保父进程优先执行
        //子进程中拷贝后半部分



        printf("child %ld\n",lseek(fd,0,SEEK_CUR));
    } else
    {
        perror("fork");
        return -1;
    }
    while (1)
    {
        sleep(1);
    }

    /******************main code end********************/
    close(fd_src);
    close(fd_dest);
    
    return 0;
}
