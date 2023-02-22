#ifndef __UDPCHAT_H__
#define __UDPCHAT_H__

typedef struct _protocol
{
    

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


