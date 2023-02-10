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

    struct node
    {
        int a;
        int b;
        int c;
    };
    struct node s = {3,5,6};
    struct node *pt = &s;
    printf("%d",*(int *)pt);
    return 0;
}
