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
        fprintf(stdout,"父进程1==>%d\n",getpid());
        int wstatus;  
        pid_t cpid = waitpid(pid,&wstatus,0);
        //若没有进程给该子进程收尸，该子进程会编程僵尸进程
        fprintf(stdout,"cpid = %d\n",cpid);
        fprintf(stdout,"wstatus = %d %d\n",wstatus,WEXITSTATUS(wstatus));
        if (WIFEXITED(wstatus))
        {
            fprintf(stdout,"cpid = %d,pid =%d 的子进程正常退出\n",cpid,pid);
        } else
        {
            fprintf(stdout,"cpid = %d,pid =%d 的子进程异常退出\n",cpid,pid);
        }

        //再次创建子进程
        pid_t pid1 = fork();
        if(pid1 > 0)
        {
            while (1)
            {
                fprintf(stdout,"父进程2==>%d\n",getpid());
                sleep(1);
            }
        } else if(0==pid1)
        {
            //兄弟进程2
            //兄弟进程1
            sleep(1);
            //exit(1);
            while (1)
            {
                fprintf(stdout,"兄弟进程2==>%d,父进程为==>%d\n",getpid(),getppid());
                sleep(1);
            }
            
        } else
        {
            perror("fork1");
            return -1;
        }


    } else if(0==pid)
    {
        //兄弟进程1
        sleep(1);
        //exit(1);
        while (1)
        {
            fprintf(stdout,"兄弟进程1==>%d,父进程为==>%d\n",getpid(),getppid());
            sleep(1);
        }
    } else
    {
        perror("fork");
        return -1;
    }


    return 0;
}
