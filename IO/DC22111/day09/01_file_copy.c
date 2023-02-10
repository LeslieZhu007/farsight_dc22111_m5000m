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

char buf[128] = "";
sem_t sem1;
sem_t sem2;

void * callback1(void *arg)
{
    FILE *fp = fopen("./01_file_copy.c","r");
    if(NULL == fp)
    {
        perror("fopen");
        pthread_exit(NULL);
    }

    while(1)
    {
        sleep(2);
        sem_wait(&sem1);
        bzero(buf,sizeof(buf));
        if(fgets(buf,sizeof(buf),fp)==NULL) //最后一次没有读到东西，buf为0
        {
            break;
        }
        
        sem_post(&sem2);
    }

    fclose(fp);
    pthread_exit(NULL);
}

void * callback2(void *arg)
{
    while (1)
    {
        sem_wait(&sem2);
        /*
        if(strlen(buf)==0)  //只针对字符文件
        {
            break; 
        }
        */
        printf("%s",buf);
        fflush(stdout);
        sem_post(&sem1);
    }
}


int main(int argc,const char* argv[])
{
    //创建信号量
    if(sem_init(&sem1,0,1) <0)
    {
        perror("sem_init");
        return -1;
    }

    if(sem_init(&sem2,0,0) <0)
    {
        perror("sem_init");
        return -1;
    }

    pthread_t tid1,tid2;
    //读
    if(pthread_create(&tid1,NULL,callback1,NULL)!=0)
    {
        fprintf(stderr,"pthread_create failed __%d__\n",__LINE__);
        return -1;
    }

    //pthread_detach(tid1);

    //打印
    if(pthread_create(&tid2,NULL,callback2,NULL)!=0)
    {
        fprintf(stderr,"pthread_create failed __%d__\n",__LINE__);
        return -1;
    }
    
    //阻塞等待
    pthread_join(tid1,NULL);
    pthread_cancel(tid2);
    pthread_join(tid2,NULL);

    sem_destroy(&sem1);
sem_destroy(&sem2);

}
