#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    void *p = malloc(100);
    printf("sizeof(p)=%ld",sizeof(p));
    printf("sizeof(*p)=%ld",sizeof(*p));

    return 0;
}
