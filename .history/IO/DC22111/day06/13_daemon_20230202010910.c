#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(int argc, char const *argv[])
{
    pid_t pid = fork();
    if(0==pid)
    {
        //1.创建新的进程组，会话组
        pid_t sid = setsid();
        printf("sid = %d\n",sid);
        //2.修改运行目录为不可卸载的文件
        chdir("/");
        
        //umask清零
        umask(0);

        //关闭所有从父进程继承过来的文件描述符：继承到的文件描述符不会使用，浪费资源，所以关闭
        for (int i = 0; i < getdtablesize(); i++)
        {
            close(i);
        }
        


        printf("pid=%d,ppid=%d\n",getpid(),getppid());

        while (1)
        {
            //功能代码
            sleep(1);
        }
        
    }
    sleep(1);

    return 0;
}
