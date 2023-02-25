#include "dictionary.h"  

//main文件仅用于测试
int main(int argc, char const *argv[])
{
    char *time_buf[128] = {0};
    while (1)
    {
        get_system_time(time_buf);
        printf("%s\n",time_buf);
        sleep(1);
    }
    return 0;
}
