#include <stdio.h>



int main(int argc, char const *argv[])
{
    int a = 10;
    void *ptr;
    int **p = &ptr;
    p = &a;

    printf("*ptr = %d\n",*(int *)ptr);

    return 0;
}
