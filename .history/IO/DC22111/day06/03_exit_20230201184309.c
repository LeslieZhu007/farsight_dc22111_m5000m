#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    pid_t pid = fork();
    if(pid > 0)
    {
        while (1)
        {
            printf("this is parent,parent id is %d,child is is %d\n",getpid(),pid);
            sleep(1);
        }
        

    } else if(0==pid)
    {
        int i = 0;
        while (i < 3)
        {
            printf("this is chid,child id is %d,parent is is %d\n",getpid(),getppid());
            sleep(1);
            i++;
        }

        fprintf(stdout,"child is ready to exit");

        //_exit(0);

        exit(0);
        printf("child exits\n");
        

    } else
    {
        perror("fork");
        return -1;
    }



    return 0;
}
