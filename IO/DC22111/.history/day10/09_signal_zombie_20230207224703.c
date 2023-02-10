#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <signal.h>
#include <stdlib.h>
int count = 0;
//17号信号的处理函数
void handler(int sig)
{
    //回收僵尸进程
    pid_t cpid = 0;
    while (1)
    {
        cpid = waitpid(-1,NULL,0); 
        if (cpid <=0) //当没有僵尸进程(=0)或者没有子进程(=-1)退出循环
        {
            break;
        }
        
    }
    
    //cpid = waitpid(-1,NULL,0);   //WNOHANG也一样//收不干净，是因为在处理某个信号A的时候，再次收到A信号，会屏蔽该信号A，防止信号处理函数重新载入

    printf("====>[%d] cpid = %d\n",++count,cpid); 
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
    while (i < 100)
    {
        if(fork()==0)
        {
            //printf("pid = %d\n",getpid);
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
