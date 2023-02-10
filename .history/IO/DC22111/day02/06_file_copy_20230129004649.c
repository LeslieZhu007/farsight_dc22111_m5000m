#include <stdio.h>
#define ERR_MSG(msg) do\
{\
    fprintf(stderr,"line:%d\n",__LINE__);\
    perror(msg);\
} while (0);


int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr,"请在命令行传入文件名\n");
        return -1;
    }
    
    FILE *fp = fopen(argv[1],"r");
    if (NULL == fp)
    {
        ERR_MSG("fopen");
        return -1;
    }
    /***********main code begin*************/



    /***********main code end***************/
    if (fclose(fp) < 0)
    {
        ERR_MSG("fclose");
        return -1;
    }
    

    return 0;
}
