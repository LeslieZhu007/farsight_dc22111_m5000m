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
        while (1)
        {
            printf("child %d,parent %d\n",getpid(),getppid());
            sleep(1);
        }
        
    }
    sleep(1);

    return 0;
}
