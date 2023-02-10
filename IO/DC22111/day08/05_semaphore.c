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
#include <semaphore.h>

//互斥锁变量 （创建互斥锁 方式二）
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

//
sem_t sem;

//函数的调用不能放在全局

/*
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
*/
char buf[] = "AAAA___BBBB";

void array_reverse(char *buf,int size)
{
    int i;
    int j;
    for (i = 0,j = size - 1; i <=j; i++,j--)
    {
        char temp = buf[i];
        buf[i] = buf[j];
        buf[j] = temp;
    }
}

void print_arry(char *buf,int size)
{
    printf("数组元素为:");
    for (int i = 0; i < size; i++)
    {
        printf("%c",buf[i]);
    }
    printf("\n");
}
int flags = 0;
void *callback(void *arg)
{
    
    int size = strlen(buf);
    int i =0;
    while (i<1000)
    {
        
        /************临界区*************/
        //P操作
        if (sem_wait(&sem) < 0)
        {
            perror("sem_wait");
            break;
        }
        
        print_arry(buf,size);

        //V操作
        if (sem_post(&sem) < 0)
        {
            perror("sem_post");
            break;
        }
        
        /************临界区*************/
       
        
        //i++;
    }
    pthread_exit(NULL);
}

void *callback1(void *arg)
{
    
    int size = strlen(buf);
    int i = 0;
    while (i<1000)
    {
        
       
        /************临界区*************/
        //P操作
        if (sem_wait(&sem) < 0)
        {
            perror("sem_wait");
            break;
        }
        array_reverse(buf,size);

        //V操作
        if (sem_post(&sem) < 0)
        {
            perror("sem_post");
            break;
        }
        /************临界区*************/
         
        
        //sleep(1);
        //i++;
    }
    pthread_exit(NULL);

}

int main(int argc, char const *argv[])
{
   //创建信号量
   if(sem_init(&sem,0,1) < 0)
   {
     perror("sem_init");
     return -1;
   }
    //创建两个线程，一个用于打印，一个用于倒置
    pthread_t tid,tid1;
    if (pthread_create(&tid,NULL,callback,NULL) < 0)
    {
        fprintf(stderr,"pthread_create failed\n");
        return -1;
    }

    pthread_detach(tid); //tid设置分离态，pthread_join不阻塞

    if (pthread_create(&tid1,NULL,callback1,NULL) < 0)
    {
        fprintf(stderr,"pthread_create failed\n");
        return -1;
    }

    pthread_join(tid1,NULL);

    //销毁放在join之后
    if (sem_wait(&sem) < 0)
    {
        perror("sem_destroy");
        return -1;
    }
    return 0;
}
