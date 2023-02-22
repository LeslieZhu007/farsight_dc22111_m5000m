#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    char buf[128] = {0};
    ssize_t ret = 0;
    while (1)
    {
        ret = read(0,buf,sizeof(buf));
        printf("%ld:%s\n",ret,buf);
    }
    
    
    return 0;
}
