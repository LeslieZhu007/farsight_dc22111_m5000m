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

//全局变量
int a = 10;

//线程执行体
void* callback(void* arg) //void *arg = NULL
{
    int c = 12;
    //arg中存储的就是ret_c的首地址
    *(int *)arg = c;
    printf("branch thread , a= %d\n",a);
    printf("branch thread , b= %d %p\n",*(int *)arg,arg);

    printf("branch thread , c= %d %p\n",c,&c);
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
    static int d = 10;   //int *pc = (int *)malloc(sizeof(int));  *pc = 20
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int *pc = (int *)malloc(sizeof(arr));   
    //strcpy(pc,"hello world");
    //pthread_exit(&d); //退出当前线程
    pthread_exit(pc);
    return NULL;
}

int main(int argc, char const *argv[])
{
    int rev_c = 0;
    int b = 11;
    printf("main thread , a= %d\n",a);
    printf("main thread , b= %d %p\n",b,&b);
    //创建线程
    pthread_t tid;
    //
    int d;
    if(0!=pthread_create(&tid,NULL,callback,(void *)&rev_c))
    {
        fprintf(stderr,"pthread_create failed,lines: %d",__LINE__);
    }
    printf("main thread d=%d\n",d);

    // int i = 0;
    // while (i < 2)
    // {
        printf("this is main function c= %d %p line: %d \n",rev_c,&rev_c,__LINE__);
    //     sleep(1);
    //     i++;
    // }
    //阻塞等待tid线程退出
    void *ptr;
    //&ptr指向ptr这个指针,pthread_join会将pthread_exit传递的值
    //也就是&c，存储到&ptr指向的空间
    //所以&c会被赋值给&ptr指向的内存空间
    //即&c会被赋值给ptr,ptr=&c
    pthread_join(tid,&ptr);
    //printf("%d\n",*(int *)ptr);
    printf("%s\n",(int *)ptr[0]);
    printf("main thread exits\n");
    return 0;
}
