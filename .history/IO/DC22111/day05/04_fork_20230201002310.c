#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char const *argv[])
{
    int fd = open("test.txt",O_WRONLY|O_CREAT|O_TRUNC,0664);
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
        printf("parent %ld\n",lseek(fd,0,SEEK_CUR));
    } else
    {
        perror("fork");
        return -1;
    }
    
    return 0;
}
