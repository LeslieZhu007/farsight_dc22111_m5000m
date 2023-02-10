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
            printf("process id==> %d,parent id==> %d\n",getpid(),getppid());
            sleep(1);
            i++;
        }
        
    } else if(0==pid)
    {
        return 0;
        
    } else
    {
        perror("fork");
        return -1;
    }


    return 0;
}
