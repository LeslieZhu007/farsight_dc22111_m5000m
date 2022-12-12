#include<stdio.h>
#include <sys/epoll.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#define MAX_EVENTS 10

char buf[128] = {0};

int main(int argc,const char* argv[])
{
	int epollfd,ctlret,i,fd,ret;
 struct epoll_event event;
 struct epoll_event revents[MAX_EVENTS];
	epollfd = epoll_create(1);
   if (epollfd == -1) {
	   perror("epoll_create");
	   exit(EXIT_FAILURE);
   }

   for(i = 1;i < argc;i++)
   {
		fd = open(argv[i],O_RDWR);
		if(fd == -1)
		{
			perror("open");
			exit(-1);
		}
		event.events = EPOLLIN;
		event.data.fd = fd;

		ctlret =  epoll_ctl(epollfd,EPOLL_CTL_ADD,fd,&event);
		if(ctlret == -1)
		{
			perror("epoll_ctl");
			exit(-1);
		}
   }

   while(1)
   {
		
		ret = epoll_wait(epollfd,revents,MAX_EVENTS,-1);
		if(ret == -1)
		{
			perror("epoll wait error");
			return -1;
		}


		for(i = 0;i < ret;i++)
		{
			if(revents[0].events&EPOLLIN)
			{
				memset(buf,0,sizeof(buf));
				read(revents[i].data.fd,buf,sizeof(buf));

				printf("fd = %d,data = %s\n",revents[i].data.fd,buf);
			}


		}



   }
   		for(i = 0;i < getdtablesize();i++)
		{
			close(i);
		}
		

	return 0;
}
