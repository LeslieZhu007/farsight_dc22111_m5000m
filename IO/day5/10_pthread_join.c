#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *ThreadFun1(void *arg)
{
    static char buf[] = "hello world";
    int num = 0;
    while(1)
    {
        num++;
        printf("子线程1:%#lx正在执行...\n", pthread_self());
        sleep(1);

        if(num == 8)
        {
            pthread_exit(buf);
        }
    }
}

void *ThreadFun2(void *arg)
{
    static int i = 888;
    int num = 0;
    while(1)
    {
        num++;
        printf("子线程2:%#lx正在执行...\n", pthread_self());
        sleep(1);

        if(num == 5)
        {
            pthread_exit(&i);
        }
    }
}


int main(int argc, char const *argv[])
{
    printf("主控线程%#lx正在执行...\n", pthread_self());

    //使用pthread_create创建子线程
    pthread_t thread1;
    if(pthread_create(&thread1, NULL, ThreadFun1, NULL) != 0)
    {
        perror("pthread_create error");
        exit(1);
    }

    pthread_t thread2;
    if(pthread_create(&thread2, NULL, ThreadFun2, NULL) != 0)
    {
        perror("pthread_create error");
        exit(1);
    }

    printf("thread1:%#lx, thread2:%#lx\n", thread1, thread2);
    
    int *n;
    pthread_join(thread2, (void **)&n);
    printf("*n = %d\n", *n);

    char *s;
    pthread_join(thread1, (void **)&s);
    printf("s = %s\n", s);

    return 0;
}
