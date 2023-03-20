#include <stdio.h>
int main(int argc, char const *argv[])
{
    int i;
    int* p1;
    char *p2;
    float *p3;
    p1 = &i;
    printf("0x7ffd51315e5c = %d",*((int *)0x7ffd51315e5c));

    printf("%p %p%d\n",p1,&i,i);
    printf("%d %ld %p\n",sizeof(int *),sizeof(p1),&p1);
    printf("%d %ld %p\n",sizeof(char *),sizeof(p2),&p2);
    printf("%d %ld %p\n",sizeof(float *),sizeof(p3),&p3);
    return 0;
}
