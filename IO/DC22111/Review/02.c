#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    FILE *fp;
    fp = fopen(argv[1],"w");
    if(NULL == fp)
    {
        perror("fopen fp\n");
        return -1;
    }

    int arr[3] = {97,98,99};
    int ret = fwrite(arr,sizeof(arr),1,fp);
    printf("ret = %d\n",ret);
   

    if(fclose(fp) < 0)
    {
        perror("fp fclose");
        return -1;
    }

    return 0;
}