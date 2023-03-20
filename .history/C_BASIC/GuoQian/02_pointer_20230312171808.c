#include <stdio.h>
int main(int argc, char const *argv[])
{
    int i;
    int* p1;
    char *p2;
    float *p3;
    p1 = &i;

    printf("%0X %0X %d\n",p1,&i,i);
    printf("%d %ld %0X\n",sizeof(int *),sizeof(p1),&p1);
    printf("%d %ld %0X\n",sizeof(char *),sizeof(p2),&p2);
    printf("%d %ld %0X\n",sizeof(float *),sizeof(p3),&p3);
    return 0;
}
