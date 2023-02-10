#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,const char* argv[])
{
    char buf[128] = "";
    char buf1[128] = "";
    //在fork之前==>只有父进程执行
    int fd[2] = {0};   //父子进程共享文件描述符
    if (pipe(fd) < 0)
    {
        perror("pipe");
        return -1;
    }
    printf("pipe create success %d %d\n",fd[0],fd[1]);
    
    //创建一个子进程
    pid_t cpid = fork();
    
    if(cpid >0) //父进程
    {
        if (strcmp(buf,"quit")==0 || strcmp(buf,"quit")==0)
        {
            exit(0);
        }
        //父进程从终端获取数据
        ssize_t ret=0;
        while (1)
        {
            if (strcmp(buf,"quit")==0 || strcmp(buf,"quit")==0)
            {
                exit(0);
            }
            
            bzero(buf,sizeof(buf));
            fgets(buf,sizeof(buf),stdin);
            buf[strlen(buf)-1] = 0; //将最后一个 \n 修改为 \0
            //写入到管道文件中
            if(write(fd[1],buf,sizeof(buf))<0)
            {
                perror("write");
                return -1;
            }
            printf("父进程写入成功\n");

            sleep(1);

           //从管道中读取数据
           bzero(buf1,sizeof(buf1));
            //阻塞，管道中没有数据
           ret =  read(fd[0],buf1,sizeof(buf1));
           if(ret < 0)
           {
            perror("read");
            return -1;
           } else if(0==ret)
           {
                fprintf(stderr,"所有写端均关闭，且管道中没有数据\n");
                break;
           }
           printf("父进程进程接收到的信息====>%s\n",buf1);

        }
        
        close(fd[1]); //关闭写端
        close(fd[0]); 

    } else if(0==cpid) //子进程
    {
        if (strcmp(buf,"quit")==0 || strcmp(buf,"quit")==0)
        {
            exit(0);
        }
        //子进程中打印父进程中获取到的数据
        ssize_t ret=0;
        while (1)
        {
            //从管道中读取数据
           bzero(buf,sizeof(buf));
            //阻塞，管道中没有数据
           ret =  read(fd[0],buf,sizeof(buf));
           if(ret < 0)
           {
            perror("read");
            return -1;
           } else if(0==ret)
           {
                fprintf(stderr,"所有写端均关闭，且管道中没有数据\n");
                break;
           }
           printf("子进程接收到的信息====>%s\n",buf);

            
           //子进程接收到信息后再发送给父进程
            bzero(buf1,sizeof(buf1));
            fgets(buf1,sizeof(buf1),stdin);
            buf[strlen(buf1)-1] = 0; //将最后一个 \n 修改为 \0
            //写入到管道文件中
            if(write(fd[1],buf1,sizeof(buf1))<0)
            {
                perror("write");
                return -1;
            }
            printf("子进程写入成功\n");
        }
        close(fd[0]); //关闭读端
        close(fd[1]); //关闭写端
    } else
    {
        perror("fork");
        return -1;
    }

}