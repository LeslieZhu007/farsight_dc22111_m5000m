#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handler(int sig)
{
    printf("alarm\n");
    alarm(3);
    return;
}

int main(int argc, char const *argv[])
{
    //捕获14号信号，给14号信号注册新的处理函数
    __sighandler_t s = signal(SIGALRM,handler);
    if (SIG_ERR == s)
    {
        perror("signal");
        return -1;
    }

    alarm(3);  //非阻塞函数，设置一个定时器，4s后产生14号信号
    while (1)
    {
        printf("signal......\n");
        sleep(1);
    }
    
    return 0;
}
