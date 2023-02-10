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

//创建信号量
sem_t sem;
sem_t sem1;

int flags = 0;
int fd;
char buf[1024] = {0};
ssize_t ret = 0;
//读取数据
void *callback(void *arg)
{
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

        ret = read(fd,buf,sizeof(buf));
        sleep(1);
        while (ret <=0)
        {
            exit(0);
        }
        

        //V操作
        if (sem_post(&sem1) < 0)
        {
            perror("sem_post");
            break;
        }
        
        /************临界区*************/
       
        
        //i++;
    }
    pthread_exit(NULL);
}

//打印数据
void *callback1(void *arg)
{
    
    int i = 0;
    while (i<1000)
    {
        /************临界区*************/
        //P操作
        if (sem_wait(&sem1) < 0)
        {
            perror("sem_wait");
            break;
        }
        write(1,buf,ret);
        //V操作
        if (sem_post(&sem) < 0)
        {
            perror("sem_post");
            break;
        }
        /************临界区*************/
    }
    pthread_exit(NULL);

}

int main(int argc, char const *argv[])
{

    //
    fd = open("01_condition_variable.c",O_RDONLY);
    if(fd < 0)
    {
        perror("open");
        return -1;
    }

   //创建信号量
   if(sem_init(&sem,0,1) < 0)
   {
     perror("sem_init");
     return -1;
   }
   if(sem_init(&sem1,0,0) < 0)
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
    if (sem_destroy(&sem) < 0)
    {
        perror("sem_destroy");
        return -1;
    }
    if (sem_destroy(&sem1) < 0)
    {
        perror("sem_destroy");
        return -1;
    }
    return 0;
}