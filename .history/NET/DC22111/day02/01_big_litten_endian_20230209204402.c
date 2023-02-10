#include <stdio.h>
#include <string.h>




int main(int argc, char const *argv[])
{
    int a = 0x12345678;
    char *p = (char *)&a;
    for (int i = 0; i < 4; i++)
    {
        printf("%#x\n",p[i]);
    }
    

    union A 
    {
        int a;
        char c;
    };
    union  A b;
    b.a = 0x12345678;

    printf("%#x\n",b.c);

    return 0;
}
