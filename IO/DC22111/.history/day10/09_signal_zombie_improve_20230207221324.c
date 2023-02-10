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
    printf("cpid = %d\n",cpid);
}

//2号信号的处理方式
void handler1(int sig)
{
    //回收僵尸进程
    pid_t cpid = 0;
    cpid = waitpid(-1,NULL,0);   //WNOHANG也一样
    printf("cpid = %d\n",cpid);
}

int main(int argc, char const *argv[])
{
    //捕获17号信号
    printf("this is main....... %d\n",getpid());
    __sighandler_t s = signal(SIGCHLD,handler);
    if(SIG_ERR == s)
    {
        perror("signal");
        return -1;
    }

    //捕获2号信号  ==> 父子进程中的代码一样，但是这部分只属于父进程，查看父子进程对2号信号的处理的异同
     __sighandler_t s1 = signal(SIGCHLD,handler1);
    if(SIG_ERR == s1)
    {
        perror("signal");
        return -1;
    }




    int cpid = fork();
    if(cpid > 0)
    {
        while (1)
        {
            printf("this is parent....... %d\n",getpid());
            sleep(1);
            //waitpid(-1,NULL,WNOHANG); //非阻塞形式
        }
    } else if(0==cpid)
    {
        int i = 0;
        while (i < 3)
        {
            i++;
            printf("this is child %d\n",getpid());
            sleep(1);
        }
        //子进程退出后，父进程会收到17号信号
    } else {
        perror("fork");
        return -1;
    }
    return 0;
}
