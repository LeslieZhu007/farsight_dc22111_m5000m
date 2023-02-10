#include <stdio.h>
#include <string.h>

typedef union
{
    int a;
    char b;
} B;




int main(int argc, char const *argv[])
{
    unsigned int a = 0x12345678; //16进制形式显示
    char *p = (char *)&a;
    for (int i = 0; i < 4; i++)
    {
        printf("%#x\n",p[i]);
    }
    if (0x78 == *p)
    {
        printf("This is little endian\n");
    } else
    {
        printf("This is big endian\n");
    }
    
    printf("====================\n");

    union A 
    {
        int a;
        char c;
    };
    union  A b;
    b.a = 0x12345678;

    printf("b.c = %#x\n",b.c);


    return 0;
}
