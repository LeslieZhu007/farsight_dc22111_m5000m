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
        printf("parent....\n");
        int wstatus;  //1   256 0001 0000 0000   2 512 0010 0000 0000 
        //pid_t cpid = waitpid(pid,&wstatus,0); //阻塞等待任意子进程退出，并回收该退出子进程的资源
        pid_t cpid = waitpid(pid,&wstatus,WNOHANG);
        //若没有进程给该子进程收尸，该子进程会编程僵尸进程
        fprintf(stdout,"cpid = %d\n",cpid);
        fprintf(stdout,"wstatus = %d %d\n",wstatus,WEXITSTATUS(wstatus));
        if (WIFEXITED(wstatus))
        {
            fprintf(stdout,"cpid = %d 的子进程正常退出\n",cpid);
        } else
        {
            fprintf(stdout,"cpid = %d 的子进程异常退出\n",cpid);
        }
        
        while (1)
        {
            printf("this is parent,parent id is %d,child is is %d\n",getpid(),pid);
            sleep(1);
        }
    } else if(0==pid)
    {
        
    } else
    {
        perror("fork");
        return -1;
    }


    return 0;
}
