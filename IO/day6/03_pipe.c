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
//读写端都存在，只读不写
    //如果管道中有数据，可以正常读取，
    //如果管道中没有数据，则读函数阻塞等待 char buf[32] = {0};
	char buf[32] = {0};
    read(pipefd[0], buf, 32);
    read(pipefd[0], buf, 32);
    printf("buf = [%s]\n", buf);

    memset(buf, 0, 32);
    read(pipefd[0], buf, 32);
    printf("buf = [%s]\n", buf);




	    return 0;
}
