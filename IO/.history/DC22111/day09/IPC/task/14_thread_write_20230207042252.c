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
    char buf[128] = "";
    ssize_t ret = 0;
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
    printf("fifo1 create success\n");

    //只能用文件IO，不能用标准IO
    int fd1 = open("myfifo1",O_RDONLY);
    if(fd1 < 0)
    {
        perror("open");
        return NULL;
    }
    //printf("RDONLY open myfifo1 success\n");
    
    while(1)
    {
        //myfifo1读取数据
        bzero(buf,sizeof(buf));
        ret = read(fd1,buf,sizeof(buf));
        if(ret < 0)
        {
            perror("read");
            return NULL;
        } else if(0==ret)
        {
            fprintf(stderr,"对方进程退出\n");
            break;
        }
        printf("B==>收到 [%ld] : %s\n",ret,buf);
        if(strcasecmp(buf,"quit")==0)
        {
            exit(0);
        }
    }
    close(fd1);
}

void* callback2(void *arg)
{
    char buf[128] = "";
    ssize_t ret = 0;
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
    int fd = open("myfifo",O_WRONLY);
    if(fd < 0)
    {
        perror("open");
        return NULL;
    }
    printf("WRONLY open myfifo success\n");

     //myfifo发送数据
    while (1)
    {
        
        /************/
        bzero(buf,sizeof(buf));
        printf("B请输入>>>\n");
        fgets(buf,sizeof(buf),stdin);
        buf[strlen(buf)-1] = 0;

        if (write(fd,buf,sizeof(buf))<0)
        {
            perror("write");
            return NULL;
        }

        printf("B发出 %s 成功\n",buf);
        if(strcasecmp(buf,"quit")==0)
        {
            exit(0);
        } 
        
    }
    close(fd);
}


int main(int argc, char const *argv[])
{
    //创建两个线程，分别用作B的收和发
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

    pthread_detach(tid2);
   // pthread_join(tid1,NULL);
    pthread_join(tid1,NULL);
    return 0;
}
