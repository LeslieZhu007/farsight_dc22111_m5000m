#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <pthread.h>
#include <string.h>

char buf[] = "1234567";

void * callback(void *arg)
{
    int i = 0;
    while (i < 10)
    {
        printf("[%d] line: __%d__ \n",i,__LINE__);
        sleep(1);
        i++;
    }
    
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    
    pthread_t tid;
    if (pthread_create(&tid,NULL,callback,NULL) < 0)
    {
        fprintf(stderr,"pthread_create failed\n");
        return -1;
    }
    //分离分支线程
    pthread_detach(tid);
    //阻塞等待tid线程退出，回收tid线程资源
    pthread_join(tid,NULL);
    printf("主线程准备退出\n");
    return 0;
}
