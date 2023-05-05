#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>



char buf[128]={0};


int main(int argc,const char* argv[])
{
	int fd = open("/dev/myled",O_RDWR);
	if(fd < 0)
	{
		perror("open error");
		exit(EXIT_FAILURE);
	}

	while(1)
	{
		buf[0] = !buf[0];
		write(fd,buf,sizeof(buf));
		sleep(1);
	}


	close(fd);
	return 0;
}
