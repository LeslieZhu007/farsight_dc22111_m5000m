#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char const *argv[])
{
    int cpid = fork();
    if(cpid > 0)
    {
        
        while (1)
        {
            printf("this is parent....... %d\n",getpid());
            sleep(1);
            waitpid(-1,NULL,WNOHANG); //非阻塞形式
        }
        

    } else if(0==cpid)
    {
        int i = 0;
        while (i < 3)
        {
            i++;
            printf("this is child %d\n",getpid());
            sleep(1);
        }

    } else {
        perror("fork");
        return -1;
    }
    return 0;
}
