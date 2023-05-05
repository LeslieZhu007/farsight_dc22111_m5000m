#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#define COUNT 3

char buf[128] = {0};
int main(int argc,const char* argv[])
{
	int fd = open("/dev/mycdev0",O_RDWR);
	if(fd < 0)
	{
		perror("open error");
		exit(EXIT_FAILURE);
	}

	write(fd,buf,sizeof(buf));
	read(fd,buf,sizeof(buf));


	close(fd);
	return 0;
}
