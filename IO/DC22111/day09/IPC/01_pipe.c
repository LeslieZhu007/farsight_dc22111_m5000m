#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(int argc,const char* argv[])
{
    char buf[128] = "";
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
        //父进程中没有读端
        close(fd[0]);
        //父进程从终端获取数据
        while (1)
        {
            bzero(buf,sizeof(buf));
            fgets(buf,sizeof(buf),stdin);
            buf[strlen(buf)-1] = 0; //将最后一个 \n 修改为 \0
            //写入到管道文件中
            if(write(fd[1],buf,sizeof(buf))<0)
            {
                perror("write");
                return -1;
            }
            printf("写入成功\n");
        }
        
        close(fd[1]); //关闭写端

    } else if(0==cpid) //子进程
    {
        //子进程中没有用到写端
        close(fd[1]);
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
           printf("====>%s\n",buf);
        }
        close(fd[0]); //关闭读端
    } else
    {
        perror("fork");
        return -1;
    }

}