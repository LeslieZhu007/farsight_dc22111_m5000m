#include <stdio.h>
#include <signal.h>

void handler(int sig)
{
    printf("sig = %d\n",sig);
    return;
}

int main(int argc, char const *argv[])
{
    //捕获 2) SIGINT信号
    signal(2,)
    


    return 0;
}
