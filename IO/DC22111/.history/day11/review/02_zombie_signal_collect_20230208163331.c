#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
int count = 0;

void handler(int sig)
{

}

int main(int argc, char const *argv[])
{
    //捕获17号信号
    __sighandler_t s = signal(SIGCHLD,handler);
    if (SIG_ERR == s)
    {
        perror("signal");
        return -1;
    }
    
    int i = 0;
    int cpid = fork();
    if (cpid > 0)
    {
        /* code */
    } else if (0 == cpid)
    {

        int i = 0;
        while (i < 200)
        {
            exit(0);
        }
        i++;
        

    } else
    {
        perror("fork");
        return -1;
    }
    


    return 0;
}
