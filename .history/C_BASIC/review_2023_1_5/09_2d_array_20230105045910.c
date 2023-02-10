#include <stdio.h>

int a[3][4] = {{1,3,5,7},{9,11,13,15},{17,19,21,23}};

int main(int argc, char const *argv[])
{
    int i;
    int *p;
    int (*b)[4];
    b = &a[1];
    p = b[0];
    for (int i = 1; i <= 4;p=p+2,i++)
    {
        printf("%d\t",*p);
    }
    printf("\n");

    

    return 0;
}
