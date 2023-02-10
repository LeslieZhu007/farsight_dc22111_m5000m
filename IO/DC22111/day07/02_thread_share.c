#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <pthread.h>

//全局变量
int a = 10;

//线程执行体
void* callback(void* arg) //void *arg = NULL
{
    int c = 12;
    printf("branch thread , a= %d\n",a);
    printf("branch thread , b= %d %p\n",*(int *)arg,arg);
    // int d = 13;
    // arg = (void *)&d;
    int i = 0;
    while (i < 2)
    {
        printf("hello world: %d \n",__LINE__);
        sleep(1);
        i++;
    }
    printf("branch thread exits\n");
    return NULL;
}

int main(int argc, char const *argv[])
{
    int b = 11;
    printf("main thread , a= %d\n",a);
    printf("main thread , b= %d %p\n",b,&b);
    //创建线程
    pthread_t tid;
    //
    int d;
    //if(0!=pthread_create(&tid,NULL,callback,(void *)&d))
    if(0!=pthread_create(&tid,NULL,callback,(void *)&b))
    {
        fprintf(stderr,"pthread_create failed,lines: %d",__LINE__);
    }
    printf("main thread d=%d\n",d);

    int i = 0;
    while (i < 2)
    {
        printf("this is main function line: %d \n",__LINE__);
        sleep(1);
        i++;
    }
    printf("main thread exits\n");
    return 0;
}
