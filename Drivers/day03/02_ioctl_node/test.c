#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include "myled.h"

char buf[128]={0};
int data = 0;

image_t image = {100,200,"png"};
image_t image02;
char send01[128] = "This message is sent from ubuntu";

int main(int argc,const char* argv[])
{
	int fd = open("/dev/myled",O_RDWR);
	if(fd < 0)
	{
		perror("open error");
		exit(EXIT_FAILURE);
	}
	//IMAGE_STRUCT
	int ret01 = ioctl(fd,IMAGE_STRUCT,&image);
	if(ret01 < 0)
	{
		perror("IMAGE_STRUCT ioctl error");
	}
	printf("image received from kernel space,height = %d,width = %d,image_type = %s\n",image.height,image.width,image.image_type);		//CHR_BUF
	int ret02 = ioctl(fd,CHR_BUF,send01);
	if(ret02 < 0)
	{
		perror("CHR_BUF ioctl error");
	}


	while(1)
	{
		/*
		   buf[0] = !buf[0];
		   write(fd,buf,sizeof(buf));
		   */






		data = !data;
		int ret = ioctl(fd,LED2_OP,&data);
		if(ret < 0)
		{
			perror("ioctl error");
		}
		sleep(1);
	}


	close(fd);
	return 0;
}
