#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
 #include <unistd.h>



int main(int argc,const char * argv[])
{

//	int fd = open("./a.txt",O_RDONLY);
	char buf[32]={0};
	ssize_t s;
	int fd = open("./a.txt",O_RDONLY);
	if(fd<0)
	{
		perror("fail to open");
		printf("%d\n",fd);
		return -1;

	}


	printf("%d\n",fd);

	s = read(fd,buf,32);

	printf("buf:%s byte:%d\n",buf,s);

	close(fd);
	return 0;
}
