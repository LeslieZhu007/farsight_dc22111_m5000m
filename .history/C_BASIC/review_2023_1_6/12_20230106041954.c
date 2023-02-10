#include <stdio.h>
#include <unistd.h>
#define MAX 255
int main(int argc, char const *argv[])
{
    unsigned char A[MAX],i;
    //死循环
    //unsigned char 范围: //0-255
    unsigned char a = 256;
    printf("a = %u\n",a);
    for (int i = 0; i <=MAX; i++)
    {
        A[i] = i;
        sleep(1);
        printf("***\n");
    }
    return 0;
}
