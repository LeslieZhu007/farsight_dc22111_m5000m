#include <stdio.h>


int main(int argc, char const *argv[])
{
    int a = 10;
    void *p ;
    p = &a;
    printf("&a=%p p = %p\n",&a,p);
    printf("a=%d *p=%d\n",a,*(int *)p);
    return 0;
}
