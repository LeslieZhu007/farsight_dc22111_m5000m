#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[3] = {1,2,3};
    int *p = a;
    printf("a=%p\n&a=%p\n&a+1=%p\n",a,&a,&a+1);

    int b[5] = {1,2,3,4,5};
    int *q = &b+1;
    printf("*q=%d ",*(q-1));


    printf("sizeof(q)=%d\n",sizeof(q));
    
    return 0;
}
