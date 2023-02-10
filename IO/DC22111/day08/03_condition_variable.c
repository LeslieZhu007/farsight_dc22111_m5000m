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

//业务场景: 先打印再翻转，即使翻转抢到互斥锁也要让出

//互斥锁变量 （创建互斥锁 方式二）
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

//条件变量
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

//条件变量需要再加一个标志位
int flag = 0; //0 打印  1 倒置  控制线程运行的时机

//函数的调用不能放在全局
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
void *callback(void *arg)
{
    
    int size = strlen(buf);
    int i =0;
    while (i<1000)
    {
        
        /************临界区*************/
        //上锁
        pthread_mutex_lock(&mutex);

        //如果不是当前线程要访问的时机，则需要让当前线程休眠
        if (flag!=0)
        {
            //1.解开互斥锁，阻塞当前线程，让当前线程进入休眠阶段，等待被唤醒
            pthread_cond_wait(&cond,&mutex);
            //2. 唤醒成功后，当cpu再次调度到该线程，会尝试立即上锁
            //3.如果上锁成功，则从当前位置继续往后执行
            //4.如果上锁失败，则在当前函数位置，重新回到cond上继续休眠，等待下一次唤醒
        }
        printf("%s",buf);

        flag = 1;

        //唤醒：唤醒睡在指定条件变量上的线程
        pthread_cond_signal(&cond);

        //解锁
        pthread_mutex_unlock(&mutex);
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
        //上锁
        pthread_mutex_lock(&mutex);

        //如果不是当前线程要访问的时机，则需要让当前线程休眠
        if (flag!=1)   //1==>倒置 
        {
            //休眠
            //1.解开互斥锁，阻塞当前线程，让当前线程进入休眠阶段，等待被唤醒
            pthread_cond_wait(&cond,&mutex);
            //2.唤醒成功后，当CPU再次调度到该线程，会尝试立刻上锁
            //3.如果上锁成功，则从当前位置继续往后执行
            //4.如果上锁失败，则在当前函数位置，重新回到cond上继续休眠，等待下一次唤醒
        }

       
        putchar(10);    //'\n'

        array_reverse(buf,size);

        flag = 0;

        //唤醒：唤醒睡在指定条件变量上的线程
        pthread_cond_signal(&cond);

        //解锁
        pthread_mutex_unlock(&mutex);
        /************临界区*************/
         
        
        //sleep(1);
        //i++;
    }
    pthread_exit(NULL);

}

int main(int argc, char const *argv[])
{
    //创建条件变量，方式2
    /*
    if(pthread_cond_init(&cond,NULL)!=0)
    {
        fprintf(stderr,"pthread_cond_init failed __%d__\n",__LINE__);
    }
    */
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
    //销毁互斥锁
    pthread_mutex_destroy(&mutex);
    //销毁条件变量
    pthread_cond_destroy(&cond);
    return 0;
}
