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
    
    printf("====================\n");

    union A 
    {
        int a;
        char c;
        char d;
        char e;
        char f;
    };
    union  A b;
    b.a = 0x12345678;

    printf("b.c = %#x\n",b.c);
    printf("b.d = %#x\n",b.d);
    printf("b.e = %#x\n",b.e);
    printf("b.f = %#x\n",b.f);

    return 0;
}
