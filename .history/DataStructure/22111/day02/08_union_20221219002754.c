#include <stdio.h>

union Test
{
    char value1;
    int value2;
    double value3;
} ;


int main(int argc, char const *argv[])
{
    //union Test t1 = {'A',24,99.5};
    union Test t1 = {'A'};
    t1.value1 = 'G';
    t1.value2 = 520;
    t1.value3 = 3.14;

    printf("t1.value1=%c\n",t1.value1);
    printf("t1.value2=%d\n",t1.value2);
    printf("t1.value3=%.2lf\n",t1.value3);



    return 0;
}
