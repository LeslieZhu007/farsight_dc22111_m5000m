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
typedef struct
{
    int fd_r;
    int fd_w;
    ssize_t size
} info;
/*
    要求创建两个线程拷贝文件，
    其中一个线程拷贝前半部分
    另外一个线程拷贝后半部分
*/

//互斥锁变量 （创建互斥锁 方式二）
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *callback(void *arg)
{
    int fd_r = ((info *)arg)->fd_r;
    int fd_w = ((info *)arg)->fd_w;
    int size = ((info *)arg)->size;
    //修改偏移量到文件开头
    off_t offset = 0; //记录前半部分的偏移量使用
 
    char c = 0;
    /************临界区*************/
    //循环第一次写一次，
    char c = 0;
    for(int i = 0;i < size/2 ;i++)
    {

    }
       
    printf("前半部分拷贝完毕\n");
   
    pthread_exit(NULL);
}

void *callback1(void *arg)
{
    
    int fd_r = ((info *)arg)->fd_r;
    int fd_w = ((info *)arg)->fd_w;
    int size = ((info *)arg)->size;
 
    /************临界区*************/
    //上锁
    pthread_mutex_lock(&mutex);
   
    pthread_mutex_unlock(&mutex);
    /************临界区*************/
    pthread_exit(NULL);

}

int main(int argc, char const *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr,"请输入两个文件名\n");
        return -1;
    }
    int fd_r = open(argv[1],O_RDONLY);
    int fd_w = open(argv[2],O_WRONLY|O_TRUNC|O_CREAT,0664);
    if (fd_r < 0|| fd_w < 0)
    {
        perror("open");
        return -1;
    }
    off_t size = lseek(fd_r,0,SEEK_END);
    info file_msg;
    file_msg.fd_r = fd_r;
    file_msg.fd_w = fd_w;
    file_msg.size = size;

    //创建两个线程，一个用于打印，一个用于倒置
    pthread_t tid,tid1;
    if (pthread_create(&tid,NULL,callback,&file_msg) < 0)
    {
        fprintf(stderr,"pthread_create failed\n");
        return -1;
    }

    //pthread_detach(tid); //tid设置分离态，pthread_join不阻塞

    if (pthread_create(&tid1,NULL,callback1,&file_msg) < 0)
    {
        fprintf(stderr,"pthread_create failed\n");
        return -1;
    }

    pthread_join(tid1,NULL);

    //销毁放在join之后
    pthread_mutex_destroy(&mutex);
    return 0;
}
