#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void* callback1(void *arg)
{
    umask(0);
    if(mkfifo("myfifo",0777)<0)
    {
        printf("errno = %d\n",errno);
        //#define EEXITST 17 ==> 文件存在的错误排除
        if(17!=errno)
        {
            perror("mkfifo");
            return NULL;
        }
    }
    printf("fifo create success\n");
     //只能用文件IO，不能用标准IO
    int fd = open("myfifo",O_RDONLY);
    if(fd < 0)
    {
        perror("open");
        return NULL;
    }
    //printf("RDONLY open myfifo success\n");

    /*****************************/
    char buf[128] = "";
    ssize_t ret = 0;
    while (1)
    {
        bzero(buf,sizeof(buf));
        ret = read(fd,buf,sizeof(buf));
        if(ret < 0)
        {
            perror("read");
            return NULL;
        } else if(0==ret)
        {
            fprintf(stderr,"对方进程退出\n");
            break;
        }
        printf("A 接收==>[%ld] : %s\n",ret,buf);
        if(strcasecmp(buf,"quit")==0)
        {
            pthread_exit(NULL);
        }   
    }
    close(fd);
}

void* callback2(void *arg)
{
    umask(0);
    if(mkfifo("myfifo1",0777)<0)
    {
        printf("errno = %d\n",errno);
        //#define EEXITST 17 ==> 文件存在的错误排除
        if(17!=errno)
        {
            perror("mkfifo1");
            return NULL;
        }
    }
    printf("fifo create success\n");

    //只能用文件IO，不能用标准IO
    int fd1 = open("myfifo1",O_WRONLY);
    if(fd1 < 0)
    {
        perror("open");
        return NULL;
    }
    printf("WRONLY open myfifo1 success\n");

    //myfifo读取数据
    char buf[128] = "";
    ssize_t ret = 0;
    while(1)
    {
        //myfifo1写入数据
        bzero(buf,sizeof(buf));
        printf("A请输入>>>\n");
        fgets(buf,sizeof(buf),stdin);
        buf[strlen(buf)-1] = 0;

        if (write(fd1,buf,sizeof(buf))<0)
        {
            perror("write");
            return NULL;
        }
        printf("A发送 %s 成功\n",buf);
        if(strcasecmp(buf,"quit")==0)
        {
            pthread_exit(NULL);
        }      
    }
    close(fd1);
}

int main(int argc, char const *argv[])
{
    //创建两个线程，分别用作A的收和发
    pthread_t tid1,tid2;
    if(pthread_create(&tid1,NULL,callback1,NULL)!=0)
    {
        perror("pthread_create");
        return -1;
    }

    if(pthread_create(&tid2,NULL,callback2,NULL)!=0)
    {
        perror("pthread_create");
        return -1;
    }


    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    return 0;
}
