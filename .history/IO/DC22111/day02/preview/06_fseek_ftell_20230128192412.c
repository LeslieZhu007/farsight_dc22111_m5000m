#include <stdio.h>
#include <time.h>
#include <unistd.h>
#define ERR_MSG(msg) do\
{\
    printf("line:%d\n",__LINE__);\
    perror(msg);\
} while (0);

int main(int argc, char const *argv[])
{
    FILE *fp = fopen("./fputs.txt","r");
    if(NULL == fp)
    {
        ERR_MSG("fopen");
        return -1;
    }
    printf("fopen success\n");

    /*********code main body begin************/
    if(fseek(fp,0,SEEK_END) < 0)
    {
        ERR_MSG("fseek");
        return -1;
    }
    printf("fseek success\n");
    long size = ftell(fp);
    printf("%ld\n",size);

    /*********time************/
    time_t t1;
    time(&t1);
    printf("t1 = %ld\n",t1);

    time_t t2;
    t2 = time(NULL);
    printf("t2 = %ld\n",t2);

    while (1)
    {
        t2 = time(NULL);
        struct tm *info = NULL;
        info = localtime(&t2);
        /*
        struct tm {
        int tm_sec; /* Seconds (0-60) */
        int tm_min; /* Minutes (0-59) */
        int tm_hour; /* Hours (0-23) */
        int tm_mday; /* Day of the month (1-31) */
        int tm_mon; /* Month (0-11) */ //month = tm_mon+1;
        int tm_year; /* Year - 1900 */ //year = tm_year+1900;
        int tm_wday; /* Day of the week (0-6, Sunday = 0) */
        int tm_yday; /* Day in the year (0-365, 1 Jan = 0) */
        int tm_isdst; /* Daylight saving time 
        };*/
        printf("%4d-%02d-%02d %02d:%02d:%02d\r",\
        info->tm_year+1900,info->tm_mon+1,info->tm_mday,\
        info->tm_hour,info->tm_min,info->tm_sec);

        fflush(stdout);
        sleep(1);
    }

    printf("getdtablesize() = %d\n",getdtablesize());
    


    /*********code main body end************/
    if (fclose(fp) <0 )
    {
        ERR_MSG("fclose");
        return -1;
    }
    printf("fclose success\n");
    return 0;
}

