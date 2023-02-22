#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

/*
int select(int nfds, fd_set *readfds, fd_set *writefds,fd_set *exceptfds, struct timeval *timeout);

__fd_mask fd_bits[__FD_SETSIZE/__NFDBITS]   //__fd_mask ==> long int

struct
{
    long fd_bits[20];
}

fd_set *readfds   读集合
fd_set *writefds  写集合
fd_set *exceptfds 其他集合
struct timeval *timeout 超时时间，可填NULL

nfds should be set to the highest-numbered file descriptor in any of  the  three  sets,
plus  1.  The indicated file descriptors in each set are checked, up to this limit (but
see BUGS).

The timeout argument specifies the interval that select() should block  waiting  for  a
file descriptor to become ready.  The call will block until either:

*  a file descriptor becomes ready;
*  the call is interrupted by a signal handler; or
*  the timeout expires.

Note  that the timeout interval will be rounded up to the system clock granularity, and
kernel scheduling delays mean that the blocking interval may overrun by a small amount.
If  both  fields  of the timeval structure are zero, then select() returns immediately.
(This is useful for polling.)  If timeout is NULL  (no  timeout),  select()  can  block
indefinitely.

返回值
>0    
=0    超时
= -1  失败，更新errno
RETURN VALUE
    On success, select() and pselect() return the number of file descriptors  contained  in
    the  three  returned descriptor sets (that is, the total number of bits that are set in
    readfds, writefds, exceptfds) which may be zero if the timeout expires before  anything
    interesting happens.  On error, -1 is returned, and errno is set to indicate the error;
    the file descriptor sets are unmodified, and timeout becomes undefined.
*/
int main(int argc, char const *argv[])
{
    fd_set rfds;
    struct timeval tv;
    int retval;

    /* Watch stdin (fd 0) to see when it has input. */

    FD_ZERO(&rfds);
    FD_SET(0, &rfds);

    /* Wait up to five seconds. */

    tv.tv_sec = 5;
    tv.tv_usec = 0;

    retval = select(1, &rfds, NULL, NULL, &tv);
    /* Don't rely on the value of tv now! */

    if (retval == -1)
        perror("select()");
    else if (retval)
        printf("Data is available now.\n");
        /* FD_ISSET(0, &rfds) will be true. */
    else
        printf("No data within five seconds.\n");

    exit(EXIT_SUCCESS);
    


    return 0;
}
