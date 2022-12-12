#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[])
{
	int pipefd[2];


	if(pipe(pipefd)== -1)
	{
		 perror("pipe error");
        exit(1);

	}
    printf("pipefd[0] = %d, pipefd[1] = %d\n", pipefd[0], pipefd[1]);
    
	write(pipefd[1],"abcde",5);
	write(pipefd[1],"12345678910",10);
    //注意：管道时候不允许使用lseek进行偏移的
#if 0
    if(lseek(pipefd[0], 5, SEEK_SET) == -1)
    {
        perror("lseek error");
        exit(1);
    }
#endif
    //从管道中读取数据，读取的数据会从管道中移除，如果管道中没有数据了，读操作会阻塞
    char buf[32] = {0};

	read(pipefd[0],buf,10);

	printf("buf = [%s]\n",buf);


	memset(buf,0,32);

	read(pipefd[0],buf,10);

	printf("buf = [%s]\n",buf);



	memset(buf,0,32);

	read(pipefd[0],buf,10);

	printf("buf = [%s]\n",buf);



    return 0;
}
