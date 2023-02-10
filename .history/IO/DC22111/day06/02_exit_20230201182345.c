#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>


int main(int argc, char const *argv[])
{
    pid_t pid = fork();
    if (pid > 0)
    {   
        int i = 0;
        while (i < 3)
        {
            printf("this is parent %d %d\n",getpid(),pid);
            sleep(1);
        }
        
    } else if (0 == pid)
    {
        int i = 0;
        while (i < 3)
        {
            printf("this is child %d %d\n",getpid(),pid);
            sleep(1);
            i++;
        }
        
    } else
    {

    }
    
    



    return 0;







    return 0;
}
