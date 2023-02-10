#include <stdio.h>
#include <signal.h>
#include <unistd.h>

//typedef void(*sighandler_t)(int);
void handler(int sig)
{
    printf("sig = %d\n",sig);
    return;
}

int main(int argc, char const *argv[])
{
    //捕获 2) SIGINT信号
    __sighandler_t s = signal(2,handler);
    if (SIG_ERR == s)
    {
        perror("signal");
        return -1;
    }

    printf("捕获2号信号成功  __%d__\n",__LINE__);

    while (1)
    {
        printf("this is main.........\n");
        sleep(1);
    }
    
    
    


    return 0;
}
