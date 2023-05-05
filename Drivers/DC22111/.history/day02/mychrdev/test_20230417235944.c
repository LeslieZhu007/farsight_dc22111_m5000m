#include <stdio.h>
char buf[128] = {0};
int main(int argc, char *argv[])
{
    int fd = open("/dev/mychrdev",O_RDONLY);
    if (fd < 0)
    {
        printf("open failed\n");
        return -1;
    }

    read(fd,buf,sizeof(buf));

    write(fd,buf,sizeof(buf));


}