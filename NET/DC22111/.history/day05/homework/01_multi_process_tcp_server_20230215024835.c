#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>

#define ERR_MSG(msg) do\
{\
   fprintf(stderr,"line:__%d__",__LINE__);\
   perror(msg);\
} while (0);


int main(int argc, char const *argv[])
{
    //socket
    int sfd = socket(AF_INET,SOCK_STREAM,0);
    if (sfd < 0)
    {
        ERR_MSG("socket");
        return -1;
    }
    
    //bind


    //listen



    //accept


    //receive



    //send
    
    return 0;
}
