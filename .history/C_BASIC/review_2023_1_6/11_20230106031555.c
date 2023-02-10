#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    void *p = malloc(100);
    printf("sizeof(p)=%ld\n",sizeof(p));
    printf("sizeof(*p)=%ld\n",sizeof(*p));
    printf("sizeof((int *)p)=%ld\n",sizeof((int *)p));

    return 0;
}
