#include "dictionary.h"

//获取当前系统时间
char * get_system_time()
{
    time_t cur_systime_milli = time(NULL);
    struct tm *t = localtime(&cur_systime_milli);
    

}
