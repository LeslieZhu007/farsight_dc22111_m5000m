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

    write(pipefd[1], "abcdefghijklmn", 14);

	 //只有读端，关闭写端
    //如果管道中有数据，则正常读取，如果没有数据，则read返回0

	close(pipefd[1]);

	char buf[32] = {0};

	ssize_t bytes;

	if((bytes = read(pipefd[0],buf,32)) == -1)
	{
		perror("read error");
        exit(1);
		
	}

    printf("bytes = %ld, buf = [%s]\n", bytes, buf);

	memset(buf,0,32);

	if((bytes = read(pipefd[0],buf,32)) == -1)
	{
		perror("read error");
        exit(1);
		
	}

    printf("bytes = %ld, buf = [%s]\n", bytes, buf);


    return 0;
}
