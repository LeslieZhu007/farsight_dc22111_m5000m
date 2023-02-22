#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>

#define ERR_MSG(msg) do\
{\
   fprintf(stderr,"")\
} while (0);


int main(int argc, char const *argv[])
{
    //socket
    int sfd = socket(AF_INET,SOCK_STREAM,0);
    if (sfd < 0)
    {
        /* code */
    }
    


    //bind


    //listen



    //accept


    //receive



    //send
    
    return 0;
}
