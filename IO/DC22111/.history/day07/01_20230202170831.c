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
    int i = 0;
    while(i < 2)
    {
        fork();
        i++;
    }
    return 0;
}
