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
    pid_t pid;
    pid = fork();
    if(pid > 0)
    {
      //父进程中再创建子进程
      printf("parent....\n");
      int wstatus;  //1   256 0001 0000 0000   2 512 0010 0000 0000 
      pid_t cpid = wait(&wstatus); //阻塞等待任意子进程退出，并回收该退出子进程的资源
      fprintf(stdout,"outer parent:cpid = %d,parent id = %d,child id = %d\n",cpid,getpid(),pid);

    } else if(0==pid)
    {
        sleep(1);
        fprintf(stdout,"outer child:parent id = %d,child id = %d\n",getppid(),getpid());
        while (1)
        {
            sleep(1);
        }
        printf("child exits\n");
    
    } else
    {
        perror("pid fork");
        return -1;
    }



    return 0;
}
