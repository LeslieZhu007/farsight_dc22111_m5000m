#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>



int main(int argc, char const *argv[])
{
    int cpid = fork();
    if (cpid > 0)
    {
        while (1)
        {
            char buf[128] = {0};
            fgets(buf,sizeof(buf),stdin);
            buf[strlen(buf)-1] = 0;
            if (strcasecmp(buf,"quit") == 0)
            {
                kill(0,9);
                break;
            }
        }

        printf("this is parent\n");
        wait(NULL); //阻塞等待子进程退出
    } else if ( 0 == cpid)
    {
        while (1)
        {
            printf("this is child %d %d\n",getppid(),getpid());
            sleep(1);
        }
        
        
    } else
    {
        perror("fork");
        return -1;
    }
    
    
    




    return 0;
}
