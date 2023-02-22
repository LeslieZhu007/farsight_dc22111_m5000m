#ifndef __UDPCHAT_H__
#define __UDPCHAT_H__

#define NAME_LENGTH 20
#define TEXT_LENGTH 128

typedef struct _protocol
{
    char type;
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

#define ERR_MSG(msg) do {\
    fprintf(stderr,"line: __%d__ ",__LINE__);\
    perror(msg);\
} while (0)




#endif


