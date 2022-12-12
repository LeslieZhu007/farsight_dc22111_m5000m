#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define N 32

//使用无名管道实现进程间通信

int main(int argc, char const *argv[])
{
	//无名管道只能用在亲缘关系的进程间通信
    //因为无名管道创建好之后是在内核空间开辟区域，但是本地是
    //给了两个文件描述符，这两个文件描述符是在用户空间开辟的
    //区域，所以不相关的进程基本不可能开辟的空间是同一个，所以
    //只能用在fork产生的进程间通信
 int pipefd[2];
    if(pipe(pipefd) == -1)
    {
        perror("pipe error");
        exit(1);
    }

	pid_t pid;
	if((pid = fork()) < 0)
	{
  perror("fork error");
        exit(1);

	}
	else if(pid > 0)
	{
		//父进程从终端读取数据并写入管道

		char buf[N] = {0};
		while(1)
		{
			printf("please enter a value\n");
			fgets(buf,N,stdin);
		//	buf[strlen(buf) - 1] = '\0';
			write(pipefd[1],buf,N);
		}

	}
	else
	{

		char buf[N] = {0};

		while(1)
		{	
			read(pipefd[0],buf,N);
			
			printf("buf = [%s]\n",buf);



		}	

	}






	    return 0;
}
