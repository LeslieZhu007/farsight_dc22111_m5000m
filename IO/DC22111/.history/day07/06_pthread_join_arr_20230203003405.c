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

//线程执行体
void* callback(void* arg) //void *arg = NULL
{
    int i = 0;
    while (i < 2)
    {
        printf("hello world: %d \n",__LINE__);
        sleep(1);
        i++;
    }
    printf("branch thread exits\n");
    //static int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int *pc = (int *)malloc(sizeof(arr));
    pc = arr;  
    printf("pc = %p\n",pc); 
    printf("arr = %p\n",arr); 
    //strcpy(pc,"hello world");
    //pthread_exit(&d); //退出当前线程
    pthread_exit(pc);
    return NULL;
}

int main(int argc, char const *argv[])
{
    //创建线程
    pthread_t tid;
    if(0!=pthread_create(&tid,NULL,callback,NULL))
    {
        fprintf(stderr,"pthread_create failed,lines: %d",__LINE__);
        return -1;
    }
    //阻塞等待tid线程退出
    void *ptr;
    //&ptr指向ptr这个指针,pthread_join会将pthread_exit传递的值
    //也就是&c，存储到&ptr指向的空间
    //所以&c会被赋值给&ptr指向的内存空间
    //即&c会被赋值给ptr,ptr=&c
    pthread_join(tid,&ptr);
    //printf("%d\n",*(int *)ptr);
    printf("数组元素为:");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",((int *)ptr)[i]);
    }
    printf("\n");
    printf("ptr = %p\n",ptr); 
    free(ptr);
    printf("main thread exits\n");
    
    return 0;
}
