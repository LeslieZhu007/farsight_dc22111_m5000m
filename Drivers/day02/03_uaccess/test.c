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

	fgets(buf,sizeof(buf),stdin);
	buf[strlen(buf)-1] = '\0';
	write(fd,buf,strlen(buf));

	memset(buf,0,sizeof(buf));
	read(fd,buf,sizeof(buf));
	
	printf("user data read from kernel is : %s \n",buf);

	close(fd);
	return 0;
}
