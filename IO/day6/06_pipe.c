#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int pipefd[2];

	//使用pipe函数创建一个无名管道
	if(pipe(pipefd) == -1)
	{
		perror("pipe error");
		exit(1);
	}
 	//只有写段，关闭读端
    //当执行第一个write函数时，就会产生SIGPIPE信号，意思是管道破裂，
    //这个信号产生之后默认对当前进程的处理方式是结束进程
	close(pipefd[0]);

	puts("11111111111111111111111");


	int num = 0;

	while(1)
	{
		num++;
		puts("222222222222222222");

		if(write(pipefd[1], "abcdefghijklmn", 1024) == -1)
        {
            perror("write error");
            exit(1);
        }
        printf("num = %d\n", num);
	}

	return 0;
}
