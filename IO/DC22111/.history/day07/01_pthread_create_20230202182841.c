#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <pthread.h>


int main(int argc, char const *argv[])
{
    //创建线程
    pthread_create();
    while (1)
    {
        printf("this is main function line: %d \n",__LINE__);
        sleep(1);
    }


    while (1)
    {
        printf("hello world: %d \n",__LINE__);
        sleep(1);
    }
    
    
    



    
    return 0;
}
