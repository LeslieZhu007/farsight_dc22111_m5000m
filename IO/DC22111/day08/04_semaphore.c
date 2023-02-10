#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

void * callback(void *arg)
{
    sleep(3);
    //v操作
    if (sem_post((sem_t *)arg)<0)
    {
        perror("sem_post");
        return NULL;
    }
    printf("v操作成功\n");

}
int main(int argc, char const *argv[])
{
    sem_t sem;
    if(sem_init(&sem,0,2) < 0)
    {
        perror("sem_init");
        return -1;
    }
    printf("sem_init success\n");

    //创建一个线程，V操作
    pthread_t tid;
    if (pthread_create(&tid,NULL,callback,&sem)!=0)
    {
        fprintf(stderr,"pthread_create fail __%d__\n",__LINE__);
        return -1;
    }

    //P操作
    if(sem_wait(&sem) < 0)  //2-1 ==1
    {
        perror("sem_wait");
        return -1;
    }
    printf("P operation success __%d__\n",__LINE__);

    if(sem_wait(&sem) < 0) //1-1 == 0
    {
        perror("sem_wait");
        return -1;
    }
    printf("P operation success __%d__\n",__LINE__);

    if(sem_wait(&sem) < 0) //1-1 == 0
    {
        perror("sem_wait");
        return -1;
    }
    printf("P operation success __%d__\n",__LINE__);

    pthread_join(tid,NULL);
    //销毁信号量
    if(sem_destroy(&sem) < 0) //1-1 == 0
    {
        perror("sem_destroy");
        return -1;
    }
    return 0;
}
