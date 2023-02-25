#include <stdio.h>
#include <string.h>
#define ERR_MSG(msg) do {\
    fprintf(stderr,"line: __%d__ ",__LINE__);\
    perror(msg);\
} while (0)


int main(int argc, char const *argv[])
{
    char buf[128] = {0};
    FILE *fp = fopen("dict.txt","r");
    char *ret = NULL;
    if (NULL == fp)
    {
        ERR_MSG("dict source file open");
        return -1;
    }
    
    int num = 1;
    while (1)
    {
        ret = fgets(buf,sizeof(buf),fp);
        if (NULL == ret)
        {
            break;
        } else
        {
            buf[strlen(buf)-1] = 0;
            printf("[%d] %s\n",num,buf);
            num++;
        }
        
    }
    


    return 0;
}
