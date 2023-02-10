#include <stdio.h>
#include <signal.h>
#include <unistd.h>

//typedef void(*sighandler_t)(int);
void handler(int sig)
{
    printf("sig = %d\n",sig);
    return;
}

void handler1(int sig)
{
    printf("this is handler1 sig = %d\n",sig);
    return;
}

int main(int argc, char const *argv[])
{
    printf("handler: %p   handler1:%p\n",handler,handler1);
    //捕获 20) SIGTSTP
    __sighandler_t s = signal(20,handler);
    if (SIG_ERR == s)
    {
        perror("signal");
        return -1;
    }

    printf("捕获20号信号成功 %p __%d__\n",s,__LINE__);

    s = signal(2,handler1);
    if (SIG_ERR == s)
    {
        perror("signal");
        return -1;
    }

    printf("捕获2号信号成功 %p __%d__\n",s,__LINE__);


    while (1)
    {
        printf("this is main.........\n");
        sleep(1);
    }

    return 0;
}
