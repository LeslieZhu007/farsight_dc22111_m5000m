#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    int fd = open("./open.txt",O_WRONLY|O_CREAT|O_TRUNC,0664);
    




    return 0;
}
