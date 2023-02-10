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
      


      
    } else if(0==pid)
    {
        
    
    } else
    {
        perror("pid fork");
        return -1;
    }



    return 0;
}
