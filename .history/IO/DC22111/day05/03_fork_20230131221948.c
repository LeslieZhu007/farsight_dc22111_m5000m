#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    pid_t pid = fork();
    printf("%d line:%d\n",pid,__LINE__);
    while(1)
    {
        sleep(1);
    }
    return 0;
}
