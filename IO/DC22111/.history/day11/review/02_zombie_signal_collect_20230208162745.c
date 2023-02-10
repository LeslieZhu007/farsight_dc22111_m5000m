#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
int count = 0;



int main(int argc, char const *argv[])
{
    //捕获17号信号
    __sighandler_t s = signal(SIGCHLD,handler);
    if (/* condition */)
    {
        /* code */
    }
    
    
    int cpid = fork();
    if (cpid > 0)
    {
        /* code */
    } else if (0 == cpid)
    {

    } else
    {
        perror("fork");
        return -1;
    }
    


    return 0;
}
