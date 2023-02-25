#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8888
#define IP "192.168.8.249"

#define ERR_MSG(msg) do {\
    fprintf(stderr,"line: __%d__ ",__LINE__);\
    perror(msg);\
} while (0)



//获取当前系统时间
void get_system_time();

//接收及发送的函数
int deal_cli_inter(int newfd,struct sockaddr_in cin);

//回收僵尸进程
void handler(int sig);

//数据库初始化，包括库，表的创建，以及数据的导入
void database_init();








#endif