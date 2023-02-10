#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

/*
    管道中有五个数据，读取十个
*/

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
        //父进程从终端获取数据
        while (1)
        {
            bzero(buf,sizeof(buf));
            fgets(buf,sizeof(buf),stdin);
            buf[strlen(buf)-1] = 0; //将最后一个 \n 修改为 \0
            //写入到管道文件中
            if(write(fd[1],buf,5)<0)
            {
                perror("write");
                return -1;
            }
            printf("写入成功\n");
        }
        
        

    } else if(0==cpid) //子进程
    {
        //子进程中打印父进程中获取到的数据
        ssize_t ret;
        while (1)
        {
           //从管道中读取数据
           bzero(buf,sizeof(buf));
           ret =  read(fd[0],buf,10);
           if(ret < 0)
           {
            perror("read");
            return -1;
           }
           printf("实际读取个数为: %ld\n",ret);
           printf("====>%s\n",buf);
        }
        


    } else
    {
        perror("fork");
        return -1;
    }

}