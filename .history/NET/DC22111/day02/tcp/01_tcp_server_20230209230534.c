#include <stdio.h>
 #include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>

#define ERR_MSG(msg) do {\
    fprintf(stderr,"line: __%d__ ",__LINE__);\
    perror(msg);\
} while (0)



int main(int argc, char const *argv[])
{
    //创建流式套接字  -->> TCP
    int sfd =  socket(AF_INET, SOCK_STREAM, 0);
    if (sfd < 0)
    {
        ERR_MSG("socket");
        return -1;
    }


    int bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
    
    return 0;
}
