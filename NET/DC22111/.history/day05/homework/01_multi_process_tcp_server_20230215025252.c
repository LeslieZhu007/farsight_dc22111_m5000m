#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>

#define IP "192.168.8.249"
#define PORT 8888

#define ERR_MSG(msg) do\
{\
   fprintf(stderr,"line:__%d__",__LINE__);\
   perror(msg);\
} while (0);


int main(int argc, char const *argv[])
{
    //1.socket
    int sfd = socket(AF_INET,SOCK_STREAM,0);
    if (sfd < 0)
    {
        ERR_MSG("socket");
        return -1;
    }
    
    //2.bind


    //3.listen



    //4.accept


    //receive



    //send
    
    return 0;
}
