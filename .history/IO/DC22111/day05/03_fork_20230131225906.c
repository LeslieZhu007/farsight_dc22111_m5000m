#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    printf("%d\n",__LINE__);
    int a = 10;
    pid_t pid = fork();
    //父子进程均会执行fork以下的代码
    if (pid < 0)
    {
        perror("fork");
        return -1;
    }
    
    printf("%d %d %p line:%d\n",a,pid,__LINE__);
    while(1)
    {
        sleep(1);
    }
    return 0;
}
