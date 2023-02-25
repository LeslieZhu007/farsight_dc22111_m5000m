#include <stdio.h>



int main(int argc, char const *argv[])
{
    char buf[128] = {0};
    FILE *fp = fopen("dict.txt","r");
    if (NULL == fp)
    {
        ERR_MSG("dict source file open");
        return -1;
    }
    
    while (1)
    {
        fgets(buf,sizeof(buf),fp);
    }
    


    return 0;
}
