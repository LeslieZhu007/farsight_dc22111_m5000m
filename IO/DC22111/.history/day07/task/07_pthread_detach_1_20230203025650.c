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
#define ERR_MSG(msg) do\
{\
    fprintf(stderr,"line:%d\n",__LINE__);\
    perror(msg);\
} while (0);

void print_time()
{
    printf("enter print_time............\n");
    time_t t;
    time_t t1; 
    struct tm *info = NULL;
    while (1)
    {
        system("clear");
        t = time(NULL);
        //fprintf(stdout,"%ld\n",t);

        //time_t *t1;==>指针指向不明，容易造成野指针
        time(&t1); //一级指针一般为普通变量取地址
       // fprintf(stdout,"%ld\n",t1);

        //将秒转换称日历格式
        info = localtime(&t);
        if (NULL == info)
        {
            ERR_MSG("localtime");
            return;
        }
        //stderr==>无缓冲   stdout stdin 行缓冲，\n能刷新行缓冲
        // fprintf(stderr,"%d-%02d-%02d %02d:%02d:%02d\r",\
        // info->tm_year+1900,info->tm_mon+1,info->tm_mday,\
        // info->tm_hour,info->tm_min,info->tm_sec);
        // sleep(1);

        // \r无法刷新缓冲区，\n能刷新
        printf("%d-%02d-%02d %02d:%02d:%02d\r",\
        info->tm_year+1900,info->tm_mon+1,info->tm_mday,\
        info->tm_hour,info->tm_min,info->tm_sec);
        fflush(stdout); //强制刷新
        sleep(1);
    }
    printf("exit print_time............\n");
}

void * callback(void *arg)
{
    print_time();
    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    pthread_t tid;
    if (pthread_create(&tid,NULL,callback,NULL) < 0)
    {
        fprintf(stderr,"pthread_create failed\n");
        return -1;
    }

    char buf[32] = {0};
    scanf("%s",buf);
    if (strcmp(buf,"quit")==0)
    {
        /* code */
    }
    


    pthread_join(tid,NULL);
    printf("主线程准备退出\n");
    return 0;
}
