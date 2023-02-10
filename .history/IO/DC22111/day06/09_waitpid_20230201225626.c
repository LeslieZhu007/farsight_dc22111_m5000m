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
    if(pid > 0)
    {
        
        
        while (1)
        {
            printf("this is parent,parent id is %d,child is is %d\n",getpid(),pid);
            sleep(1);
        }
    } else if(0==pid)
    {
        printf("child....\n");
        int wstatus;  
        pid_t cpid = waitpid(getppid(),&wstatus,0);
        //若没有进程给该子进程收尸，该子进程会编程僵尸进程
        fprintf(stdout,"cpid = %d\n",cpid);
        fprintf(stdout,"wstatus = %d %d\n",wstatus,WEXITSTATUS(wstatus));
        if (WIFEXITED(wstatus))
        {
            fprintf(stdout,"cpid = %d 的父进程正常退出\n",cpid);
        } else
        {
            fprintf(stdout,"cpid = %d 的父进程异常退出\n",cpid);
        }
        
    } else
    {
        perror("fork");
        return -1;
    }


    return 0;
}
