#include <stdio.h>
#include <time.h>
#include <unistd.h>
/*

   struct tm {
               int tm_sec;    /* Seconds (0-60) */
               int tm_min;    /* Minutes (0-59) */
               int tm_hour;   /* Hours (0-23) */
               int tm_mday;   /* Day of the month (1-31) */
               int tm_mon;    /* Month (0-11) */
               int tm_year;   /* Year - 1900 */
               int tm_wday;   /* Day of the week (0-6, Sunday = 0) */
               int tm_yday;   /* Day in the year (0-365, 1 Jan = 0) */
               int tm_isdst;  /* Daylight saving time
           };

       The members of the tm structure are:

       tm_sec    The number of seconds after the minute,  normally  in
                 the  range  0 to 59, but can be up to 60 to allow for
                 leap seconds.

       tm_min    The number of minutes after the hour, in the range  0
                 to 59.

       tm_hour   The  number of hours past midnight, in the range 0 to
                 23.

       tm_mday   The day of the month, in the range 1 to 31.

       tm_mon    The number of months since January, in the range 0 to
                 11.

       tm_year   The number of years since 1900.

       tm_wday   The number of days since Sunday, in the range 0 to 6.

       tm_yday   The number of days since January 1, in the range 0 to
                 365.

       tm_isdst  A flag that indicates whether daylight saving time is
                 in  effect at the time described.  The value is posi‐
                 tive if daylight saving time is in effect, zero if it
                 is not, and negative if the information is not avail‐
                 able.
*/
#define ERR_MSG(msg) do\
{\
    fprintf(stderr,"line:%d\n",__LINE__);\
    perror(msg);\
} while (0);

int main(int argc, char const *argv[])
{
    time_t t;
    time_t t1; 
    struct tm *info = NULL;
    while (1)
    {
        t = time(NULL);
        //fprintf(stdout,"%ld\n",t);

        //time_t *t1;==>指针指向不明，容易造成野指针
        time(&t1); //一级指针一般为普通变量取地址
       // fprintf(stdout,"%ld\n",t1);

        //将秒转换称日历格式
        info = localtime(&t);
        if (NULL == info)
        {
            ERR_MSG("localtime");
            return -1;
        }
        //stderr==>无缓冲   stdout stdin 行缓冲，\n能刷新行缓冲
        fprintf(stderr,"%d-%02d-%02d %02d:%02d:%02d\r",\
        info->tm_year+1900,info->tm_mon+1,info->tm_mday,\
        info->tm_hour,info->tm_min,info->tm_sec);
        sleep(1);
    }
    
    
    
    return 0;
}
