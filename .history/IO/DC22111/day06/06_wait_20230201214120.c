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
    pid_t pid,pid1;
    pid = fork();
    if(pid > 0)
    {
      //父进程中再创建子进程
       pid1 = fork();
        if(pid1 > 0)
        {
        //父进程中再创建子进程
        } else if(0==pid1)
        {

        
        } else
        {
            perror("pid1 fork");
            return -1;
        }

    } else if(0==pid)
    {
        
    
    } else
    {
        perror("pid fork");
        return -1;
    }



    return 0;
}
