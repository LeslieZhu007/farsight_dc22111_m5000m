#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/fcntl.h>

int main(int argc, char const *argv[])
{
   int fd = open("test.txt",O_WRONLY|O_CREAT|O_TRUNC,0664);
    return 0;
}
