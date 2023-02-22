#include <stdio.h>
#include <poll.h>

/*
int poll(struct pollfd *fds, nfds_t nfds, int timeout);
DESCRIPTION
       poll()  performs  a  similar  task to select(2): it waits for one of a set of file descriptors to become ready to
       perform I/O.

       The set of file descriptors to be monitored is specified in the fds argument, which is an array of structures  of
       the following form:

           struct pollfd {
               int   fd;         /* file descriptor */
               short events;     /* requested events */
               short revents;    /* returned events 
           };
*/
  

int main(int argc, char const *argv[])
{
    
    
    return 0;
}
