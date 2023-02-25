#include "dictionary.h"

//获取当前系统时间
void get_system_time(char *time_buf)
{
    time_t cur_systime_milli = time(NULL);
    struct tm *t = localtime(&cur_systime_milli);
    sprintf(time_buf,"%4d-%02d-%02d %02d-%02d-%02d",t->tm_year+1900,t->tm_mon+1,t->tm_mday,t->tm_hour,t->tm_min,t->tm_sec);
}
