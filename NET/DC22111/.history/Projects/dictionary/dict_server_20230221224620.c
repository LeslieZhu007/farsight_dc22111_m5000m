#include "dictionary.h"

//获取当前系统时间
void get_system_time()
{
    time_t cur_systime_milli = time(NULL);
    struct tm *t = localtime(&cur_systime_milli);
    char buf[128] = {0};
    //sprintf(buf,"%d-%d-%d %d-%d-%d",t->tm_year+1900,t->tm_mon+1,t->tm_mday,t->tm_hour,t->tm_min,t->tm_sec);
        fprintf(stdout,"%4d-%02d-%02d %02d-%02d-%02d",t->tm_year+1900,t->tm_mon+1,t->tm_mday,t->tm_hour,t->tm_min,t->tm_sec);

    //return buf;
}
