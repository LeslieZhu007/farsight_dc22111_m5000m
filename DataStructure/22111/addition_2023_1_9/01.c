#include <stdio.h>

int main(int argc, char const *argv[])
{
    unsigned short a = 6;
    short b = -28;
    (a+b > 6)?puts(">6"):puts("<6");
    printf("%ld\n",sizeof(a+b));
    return 0;
}
