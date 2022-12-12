#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>


#define N 300

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
		//父进程从源文件中读取数据写入到无名管道中
			int fd;
		if((fd = open(argv[1],O_RDONLY)) == -1)
		{
			perror("open error");
			exit(1);
		}

		char buf[N] = {0};
		ssize_t bytes;

		while((bytes = read(fd,buf,N)) != 0)
		{
			
			write(pipefd[1],buf,bytes);
			sleep(1);
			printf("parent process writing %ld bytes into write end of pipe\n",bytes);
		}

		wait(NULL);
	}
	else
	{

		//子进程从无名管道中读取数据写入指定目标文件中


		int fd;
		fd = open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0664);
		if(fd == -1)
		{
			perror("open error");
			exit(1);
		}

		char buf[N] = {0};
		ssize_t bytes;

		while((bytes = read(pipefd[0],buf,N)) != 0)
		{
			write(fd,buf,bytes);
			sleep(1);
			printf("child process read %ld bytes from read end of pipe\n",bytes);

			if(bytes < 300)
			{
				break;
			}
		}
		
		 puts("cp done");
        exit(0);


	}
	return 0;
}
