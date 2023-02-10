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
char buf[] = "1234567";

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

void *callback(void *arg)
{
    int size = strlen(buf);
    while (1)
    {
        print_arry(buf,size);
    }
    
}

void *callback1(void *arg)
{

}

int main(int argc, char const *argv[])
{
    /*
      //Reverse test.......
    int size = strlen(buf);
    print_arry(buf,size);
    array_reverse(buf,size);
    print_arry(buf,size);
    */

    //创建两个线程，一个用于打印，一个用于倒置
    pthread_t tid,tid1;
    if (pthread_create(&tid,NULL,callback,NULL) < 0)
    {
        fprintf(stderr,"pthread_create failed\n");
        return -1;
    }

    pthread_detach(tid);

    if (pthread_create(&tid1,NULL,callback1,NULL) < 0)
    {
        fprintf(stderr,"pthread_create failed\n");
        return -1;
    }

 
    return 0;
}
