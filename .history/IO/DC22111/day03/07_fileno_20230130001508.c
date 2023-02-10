#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    printf("%d\n",stdin->_fileno);
printf("%d\n",stdout->_fileno);
printf("%d\n",stderr->_fileno);
printf("%d\n",getdtablesize());


    FILE *fp = fopen("./fileno.txt","w");
    if(NULL == fp)
    {
        perror("fopen");
        return -1;
    }
    printf("%d\n",fp->_fileno);
    //while(1)
    {
    fp = fopen("./fileno.txt","w");
    if(NULL == fp)
    {
        perror("fopen");
        return -1;
    }
    printf("%d\n",fp->_fileno);
    }

    

    //fclose(fp);
    return 0;
}
