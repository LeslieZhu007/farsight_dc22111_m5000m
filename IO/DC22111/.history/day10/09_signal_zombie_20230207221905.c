#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <signal.h>
//17号信号的处理函数
void handler(int sig)
{
    //回收僵尸进程
    pid_t cpid = 0;
    cpid = waitpid(-1,NULL,0);   //WNOHANG也一样
    printf("====>cpid = %d\n",cpid);
}

int main(int argc, char const *argv[])
{
    //捕获17号信号
    __sighandler_t s = signal(SIGCHLD,handler);
    if(SIG_ERR == s)
    {
        perror("signal");
        return -1;
    }

    int i = 0;
    while (i < 10)
    {
        if(fork()==0)
        {
            printf("pid = %d\n",getpid);
            exit(0);
        }
        i++;
    }
    while (1)
    {
        sleep(1);
    }
    
    return 0;
}
