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
    
    int fd = open(argv[1],O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return -1;
    }

    pid_t pid = fork();
  
    if (pid > 0)
    {
        if (write(fd,"a",1) < 0)
        {
            perror("write");
            return -1;
        }

        printf("parent %ld\n",lseek(fd,0,SEEK_CUR));
        
    } else if(0 == pid)
    {
        sleep(1); //确保父进程优先执行
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
    close(fd);
    
    return 0;
}
