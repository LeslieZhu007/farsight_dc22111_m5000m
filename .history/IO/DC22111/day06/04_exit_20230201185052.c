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
    pid_t pid1,pid2;
    if((pid1=fork())==0)
    {

    } else
    {
      if ((pid2=fork())==0)
      {
        sleep(4);
        printf("info1 from child process 2");
        fflush(stderr);
        _exit(0);
      } else
      {
        wait(NULL); //阻塞等待一个子进程退出后，解除阻塞
        printf("info1 from parent process\n");
        exit(0);
      }
        
    }
    


    return 0;
}
