#include<stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc,const char* argv[])
{
	int fd = socket(AF_INET,SOCK_STREAM,0);
	if(-1==fd)
	{
		perror("socket ");
		return -1;
	}

	struct sockaddr_in destaddr = {0};
	destaddr.sin_family = AF_INET;
	destaddr.sin_port = htons(8888); 
	destaddr.sin_addr.s_addr=inet_addr("192.168.43.201");
	int result = connect(fd,(struct sockaddr *)&destaddr,sizeof(destaddr));
	if(-1==result)
	{
		perror("connect");
		return -1;
	}

	while(1)
	{
		write(fd,"hello",5);
		sleep(1);
	}
	
	return 0;
}
