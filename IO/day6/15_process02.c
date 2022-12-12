#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>


#define FIFONAME01 "myfifo01"
#define FIFONAME02 "myfifo02"

int main(int argc, char const *argv[])
{
	//使用mkfifo函数创建一个有名管道
	if(mkfifo(FIFONAME01,0664) == -1)
	{
		//如果管道文件已经存在，则不用报错退出，所以
		//将已经存在的错误码排除
		if(errno!=EEXIST)
		{
			perror("makefifo error");
			exit(1);
		}	
	}

	if(mkfifo(FIFONAME02,0664) == -1)
	{
		//如果管道文件已经存在，则不用报错退出，所以
		//将已经存在的错误码排除
		if(errno!=EEXIST)
		{
			perror("makefifo error");
			exit(1);
		}	
	}


	//fork a process

	pid_t pid;

	pid = fork();

	if(pid == -1)
	{
		perror("fork error");
		exit(1);
	}
	else if(pid > 0)
	{
		//parent process
		int fd;
		if((fd = open(FIFONAME01,O_RDWR)) == -1)
		{
			perror("open error");
			exit(1);
		}

		char buf[32] = {0};
		ssize_t readBytes;
		while(1)
		{

			readBytes = read(fd,buf,32);

			if(readBytes == -1)
			{
				perror("read error");
				exit(1);
			}

			printf("process02 parent process readBytes = %ld\n",readBytes);
			printf("process02 parent process buf = %s\n", buf);



		}
	}

	else
	{
		//child process

		int fd;
		if((fd = open(FIFONAME02,O_RDWR)) == -1)
		{
			perror("open error");
			exit(1);
		}

		ssize_t writeBytes;
		char buf[32] = {0};

		while(1)
		{
			printf("process02 child process input:\n");
			fgets(buf,32,stdin);
			writeBytes = write(fd,buf,32);

			if(writeBytes == -1)
			{
				perror("write error");
				exit(1);
			}

			printf("process02 child process writeBytes = %ld\n",writeBytes);

		}







	}






	//对有名管道进行操作
	//不管写多少数据，管道文件永远0个字节，
	//因为管道文件只是内核空间开辟区域的标识，对管道文件的操作
	//本质还是对内核空间的操作
	//有名管道的读写操作基本性质与无名管道一致
	//第二次写入的数据会保存在之前数据的后面
	//读到的数据会从管道中移除
	//如果管道中没有数据了，读操作会阻塞

	//使用open打开管道文件，然后使用read和write操作即可

	return 0;
}
