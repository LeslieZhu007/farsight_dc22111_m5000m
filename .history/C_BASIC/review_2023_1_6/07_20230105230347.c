#include <stdio.h>

void change(int *p)
{
    *p = 999;
}
int main(int argc, char const *argv[])
{
    int m = 520;
    change(&m);

    printf("m=%d\n",m);
    return 0;
}
