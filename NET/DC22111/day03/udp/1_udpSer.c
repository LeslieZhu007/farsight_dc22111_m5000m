#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>

 #define ERR_MSG(msg) do{\
     fprintf(stderr, "__%d__ ", __LINE__);\
     perror(msg);\
 }while(0)

int main(int argc, const char *argv[])
{
	//创建报式套接字
	int sfd = socket(AF_INET, SOCK_DGRAM, 0);
	if(sfd < 0)
	{
		ERR_MSG("socket");
		return -1;
	}

	//填充服务器的地址信息结构体
	struct sockaddr_in sin;
	sin.sin_family 		= AF_INET;
	sin.sin_port 		= htons(8888); 	//1024~49151
	sin.sin_addr.s_addr = inet_addr("192.168.0.12"); 	//ifconfig查找

	//绑定服务器的地址信息结构体
	if(bind(sfd, (struct sockaddr*)&sin, sizeof(sin)) < 0)
	{
		ERR_MSG("bind");
		return -1;
	}
	printf("bind success\n");

	char buf[128] = "";

	struct sockaddr_in cin;
	socklen_t addrlen = sizeof(cin);

	while(1)
	{
		bzero(buf, sizeof(buf));

		//接收数据
		if(recvfrom(sfd, buf, sizeof(buf), 0, (struct sockaddr*)&cin, &addrlen)<0)
		{
			ERR_MSG("recvfrom");
			return -1;
		}
		printf("[%s | %d]：%s\n", inet_ntoa(cin.sin_addr), ntohs(cin.sin_port), buf);

/*	
		//发送
		strcat(buf, "*_*");
		if(sendto(sfd, buf, sizeof(buf), 0, (struct sockaddr*)&cin, sizeof(cin)) < 0)
		{
			ERR_MSG("sendto");
			return -1;
		}
		*/
	}

	//关闭文件描述符
	close(sfd);

	return 0;
}
