#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <wait.h>

int main(int argc,const char* argv[])
{
    
    //在fork之前==>只有父进程执行
    int fd[2] = {0};   //父子进程共享文件描述符   父--->子
    if (pipe(fd) < 0)
    {
        perror("pipe");
        return -1;
    }
    /************************************************/

    int fd1[2] = {0};   //父子进程共享文件描述符   子---->父
    if (pipe(fd1) < 0)
    {
        perror("pipe");
        return -1;
    }
    /************************************************/

    ssize_t ret = 0;
    char buf[128] = "";
    //创建一个子进程
    pid_t cpid = fork();
    /************************************************/

    if(cpid >0) //父进程
    {
        close(fd[0]); 
        close(fd1[1]);
       
        while (1)
        {
            //父进程发送数据到管道中
            bzero(buf,sizeof(buf));
            fgets(buf,sizeof(buf),stdin);  //scanf或者fscanf不能输入空格
            buf[strlen(buf)-1]=0;
            if(write(fd[1],buf,sizeof(buf)) < 0)
            {
                perror("write");
                return -1;
            }
            if (!strcmp(buf,"quit"))
            {
                break;
            }

            /************************************************/


            //父进程从管道中读取数据
            bzero(buf,sizeof(buf));
            ret = read(fd1[0],buf,sizeof(buf));
            if(ret < 0)
            {
                perror("read");
                return -1;
            } else if(0==ret)
            {
                fprintf(stderr,"写端关闭\n");
                break;
            }
            printf("父进程接收到:%s\n",buf);

            if(!strcmp(buf,"quit"))
            {
                break;
            }
        }
        
        wait(NULL); //阻塞等待子进程退出

        close(fd[1]); 
        close(fd1[0]);
        

    } else if(0==cpid) //子进程
    {
        close(fd[1]);
        close(fd1[0]);
        
        while (1)
        {
            //子进程从管道中读取数据
            bzero(buf,sizeof(buf));
            ret = read(fd[0],buf,sizeof(buf));
            if(ret < 0)
            {
                perror("read");
                return -1;
            } else if(0==ret)
            {
                fprintf(stderr,"写端关闭\n");
                break;
            }
            printf("子进程接收到:%s\n",buf);
            if (!strcmp(buf,"quit"))
            {
                break;
            }

            /************************************************/


            //子进程发送数据到管道中
            bzero(buf,sizeof(buf));
            fgets(buf,sizeof(buf),stdin);
            buf[strlen(buf)-1]=0;
            if(write(fd1[1],buf,sizeof(buf)) < 0)
            {
                perror("write");
                return -1;
            }
            if (!strcmp(buf,"quit"))
            {
                break;
            }
        }

        close(fd[1]);
        close(fd1[0]);
        
      
    } else
    {
        perror("fork");
        return -1;
    }

}