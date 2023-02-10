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
    } else if (pid > 0) // 子进程代码区
    {
        printf("子进程====>%d %d %p line:%d\n",a,pid,&a,__LINE__);
        printf("子进程中修改a的值\n");
        a = 20;
    } else //父进程代码区
    {
        printf("父进程====>%d %d %p line:%d\n",a,pid,&a,__LINE__);
         printf("子进程中修改a的值\n");
    }
    
    
    
    while(1)
    {
        sleep(1);
    }
    return 0;
}
