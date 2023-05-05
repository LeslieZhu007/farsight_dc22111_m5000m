#include "command.h"


int main(int argc, char const *argv[])
{
    int fd1 = open("/dev/mychrdev",O_RDWR);
    if (fd1 < 0)
    {
        printf("open failed\n");
        return -1;
    }
    return 0;
}
