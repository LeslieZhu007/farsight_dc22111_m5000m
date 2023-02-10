#include <stdio.h>
#include <time.h>
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


    /*********code main body end************/
    if (fclose(fp) <0 )
    {
        ERR_MSG("fclose");
        return -1;
    }
    printf("fclose success\n");
    return 0;
}

