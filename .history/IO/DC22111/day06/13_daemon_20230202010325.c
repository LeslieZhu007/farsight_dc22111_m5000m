#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(int argc, char const *argv[])
{
    pid_t pid = fork();
    if(0==pid)
    {
        //创建新的进程组，会话组
        pid_t sid = setsid();
        printf("sid = %d\n",sid);
        //修改运行目录为不可卸载的文件
        chdir("/");
        //打开一个文件
        int fd = open("./11_orphan.c",O_RDONLY);
        if (fd < 0)
        {
            perror("open");
            return -1;
        }
        printf("文件打开成功\n");
        printf("pid=%d,ppid=%d\n",getpid(),getppid());

        while (1)
        {
            
            sleep(1);
        }
        
    }
    sleep(1);

    return 0;
}
