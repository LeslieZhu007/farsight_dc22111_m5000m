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
//读写端都存在，只写不读
    //当管道写满是，写操作会阻塞等待，默认无名管道64k字节

	int num = 0;
	while(1)
	{
		num++;
		if(write(pipefd[1], "abcdefghijklmn", 1024) == -1)
		{
	 			perror("write error");
				exit(1);
		}

		        printf("num = %d\n", num);
    }



	    return 0;
}
