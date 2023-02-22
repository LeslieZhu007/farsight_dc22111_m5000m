#ifndef __UDPCHAT_H__
#define __UDPCHAT_H__

#define NAME_LENGTH 20
#define TEXT_LENGTH 128
#define SERVER_IP "192.168.8.249"
#define SERVER_PORT 8888

typedef struct _protocol
{
    char type;  // L 登录 C 聊天 Q 退出
    char name[NAME_LENGTH];
    char text[TEXT_LENGTH];
} protocol_t;


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

#define ERR_MSG(msg) do {\
    fprintf(stderr,"line: __%d__ ",__LINE__);\
    perror(msg);\
} while (0)









#endif


