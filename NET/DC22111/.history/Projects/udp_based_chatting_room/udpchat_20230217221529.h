#ifndef __UDPCHAT_H__
#define __UDPCHAT_H__

#define NAME_LENGTH 20
#define TEXT_LENGTH 128
#define SERVER_IP "192.168.8.249"
#define SERVER_PORT 8888




#include <stdio.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <poll.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

typedef struct _protocol
{
    char type;  // L 登录 C 聊天 Q 退出
    char name[NAME_LENGTH];
    char text[TEXT_LENGTH];
} protocol_t;

#define ERR_MSG(msg) do {\
    fprintf(stderr,"line: __%d__ ",__LINE__);\
    perror(msg);\
} while (0)

//使用单向链表存储客户端的地址信息

typedef struct _node
{
    struct sockaddr_in cin;
    
    struct Node *next;

} *linklist,Node;

//创建
linklist list_create();

//尾插
int list_insert_tail(linklist L,struct sockaddr_in e);

//任意位置删
int list_delete_value(linklist L,struct sockaddr_in e);

#endif


