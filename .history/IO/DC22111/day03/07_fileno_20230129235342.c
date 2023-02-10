#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *fp = fopen("./fileno.txt","w");
    if(NULL == fp)
    {
        perror("fopen");
        return -1;
    }
    printf("%d\n",fp->_fileno);

    fclose(fp);
    return 0;
}
