#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#define COUNT 3

char buf[128] = {0};
int main(int argc,const char* argv[])
{
	int fd1,fd2;
	fd1 = open("/dev/mycdev0",O_RDWR);
	if(fd1 < 0)
	{
		perror("mycdev0 open error");
		exit(EXIT_FAILURE);
	}

	fd2 = open("/dev/input/mouse0",O_RDWR);
	if(fd2 < 0)
	{
		perror("mouse0 open error");
		exit(EXIT_FAILURE);
	}


	fd_set rfds;
	int retval;

	/* Watch stdin (fd 0) to see when it has input. */

	while(1)
	{
		FD_ZERO(&rfds);
		FD_SET(fd1, &rfds);
		FD_SET(fd2, &rfds);


		retval = select(fd2 + 1, &rfds, NULL, NULL, NULL);
		/* Don't rely on the value of tv now! */

		if (retval == -1)
		{
			perror("select()");
			return -1;
		}

		if(FD_ISSET(fd1,&rfds))
		{
			memset(buf,0,sizeof(buf));
			read(fd1,buf,sizeof(buf));
			printf("mycdev0:%s\n",buf);
		}



		if(FD_ISSET(fd2,&rfds))
		{
			memset(buf,0,sizeof(buf));
			read(fd2,buf,sizeof(buf));
			printf("mouse0:%s\n",buf);
		}


		//sleep(1);
	}

	close(fd1);
	close(fd2);
	return 0;
}
