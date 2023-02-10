#include <stdio.h>
#define ERR_MSG(msg) do\
\{
    \
\} while (0);

int main(int argc, char const *argv[])
{
    FILE *fp = fopen("./fputs.txt","w");
    if(NULL == fp)
    {
        perror("fopen");
        return -1;
    }
    





    return 0;
}
