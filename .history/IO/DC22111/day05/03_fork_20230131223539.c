#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    printf("%d\n",__LINE__);
    pid_t pid = fork();
    printf("%d line:%d\n",pid,__LINE__);
    while(1)
    {
        printf("%d line:%d\n",pid,__LINE__);
        sleep(1);
    }
    return 0;
}
