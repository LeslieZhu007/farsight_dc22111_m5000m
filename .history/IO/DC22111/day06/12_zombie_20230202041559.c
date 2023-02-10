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
    {   int i = 0;
        while (i <30)
        {
            printf("[%d] process id==> %d,parent id==> %d\n",i,getpid(),getppid());
            sleep(1);
            i++;
        }
        
    } else if(0==pid)
    {
        printf("**********child id is %d *************\n",getpid());
        return 0;
        
    } else
    {
        perror("fork");
        return -1;
    }


    return 0;
}
