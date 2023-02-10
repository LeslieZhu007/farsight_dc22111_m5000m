#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    void *p = malloc(100);
    printf("sizeof(p)=%ld\n",sizeof(p));
    printf("sizeof(*p)=%ld\n",sizeof(*p));
    printf("sizeof((int *)p)=%ld\n",sizeof((int *)p));
    printf("sizeof(*(int *)p)=%ld\n",sizeof(*(int *)p));
    printf("sizeof((char *)p)=%ld\n",sizeof((char *)p));
    printf("sizeof(*(char *)p)=%ld\n",sizeof(*(char *)p));
    return 0;
}
