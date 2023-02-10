#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <pthread.h>
#include <string.h>

void * callback(void *arg)
{
    int i = 0;
    while (i < 2)
    {
        printf("line: __%d__ \n",__LINE__);
        sleep(1);
        i++;
    }
    
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    
    





    return 0;
}
