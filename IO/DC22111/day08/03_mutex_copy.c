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

/*
    要求创建两个线程拷贝文件，
    其中一个线程拷贝前半部分
    另外一个线程拷贝后半部分
*/

//互斥锁变量 （创建互斥锁 方式二）
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int fd_r,fd_w;

//函数的调用不能放在全局
int copy_file(int filesize,int fd_r,int fd_w)
{
    char buf[1024] = {0};
    int copycount = 0; 
    ssize_t ret = 0;

    while(1)
    {
        bzero(buf,sizeof(buf));
        //如果剩余拷贝字节数大于sizeof(buf)
        //则一次性拷贝sizeof(buf)，让数组最大化利用
        //否则拷贝剩余个数
        if (filesize > sizeof(buf))
        {
            copycount = sizeof(buf);
        } else
        {
            copycount = filesize;
        }
        
        ret = read(fd_r,buf,copycount);

        if(ret < 0)
        {
            perror("read");
            return -1;
        } else if(0 == ret)
        {
            break;
        }

        if(write(fd_w,buf,ret)<0)
        {
            perror("write");
            return -1;
        }

        filesize -= copycount;
        if (filesize == 0)
        {
            break;
        }
        
    }

}


void *callback(void *arg)
{
    
    int size = *(int *)arg;
    sleep(1);
    
    /************临界区*************/
    //上锁
    pthread_mutex_lock(&mutex);
    //文件偏移量的修改必须放在临界区
    lseek(fd_r,size/2,SEEK_SET);  
    lseek(fd_w,size/2,SEEK_SET);

    copy_file(size/2,fd_r,fd_w);

    //解锁
    pthread_mutex_unlock(&mutex);
    /************临界区*************/
       
    printf("前半部分拷贝完毕\n");
   
    pthread_exit(NULL);
}

void *callback1(void *arg)
{
    
    int size = *(int *)arg;
    int flag = size/2;
    /************临界区*************/
    //上锁
    pthread_mutex_lock(&mutex);
    //文件偏移量的修改必须放在临界区
    lseek(fd_r,0,SEEK_SET);
    lseek(fd_w,0,SEEK_SET);
    copy_file(size/2+flag,fd_r,fd_w);
    //解锁
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
    fd_r = open(argv[1],O_RDONLY);
    fd_w = open(argv[2],O_WRONLY|O_TRUNC|O_CREAT,0664);
    if (fd_r < 0|| fd_w < 0)
    {
        perror("open");
        return -1;
    }
    off_t size = lseek(fd_r,0,SEEK_END);

    //创建两个线程，一个用于打印，一个用于倒置
    pthread_t tid,tid1;
    if (pthread_create(&tid,NULL,callback,&size) < 0)
    {
        fprintf(stderr,"pthread_create failed\n");
        return -1;
    }

    //pthread_detach(tid); //tid设置分离态，pthread_join不阻塞

    if (pthread_create(&tid1,NULL,callback1,&size) < 0)
    {
        fprintf(stderr,"pthread_create failed\n");
        return -1;
    }

    pthread_join(tid1,NULL);

    //销毁放在join之后
    pthread_mutex_destroy(&mutex);
    return 0;
}
