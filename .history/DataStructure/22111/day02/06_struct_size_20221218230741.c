#include <stdio.h>
#include <string.h>

struct A
{
    char value1; //1
};

struct B
{
    char value1; //1
    short value2; //2
};

struct C
{
    char value1; //1
    int value2; //2
};

struct D
{
    char value1; //1
    char value2; //2
};

struct E
{
    char value1; //1
    int value2; //4     ==> 12
    char value3; //1
};

struct F
{
    char value1; //1
    char value2; //1     ==> 8
    int value3; //4
};

struct G
{
    char value1; //1
    char *p; //8
};





int main(int argc, char const *argv[])
{
    printf("sizeof A = %ld\n",sizeof(struct A)); //1
    printf("sizeof B = %ld\n",sizeof(struct B)); //4
    printf("sizeof C = %ld\n",sizeof(struct C)); //8

    struct C t;
    struct B t1;
    struct D t2;
    struct E t3;
    struct F t4;
    struct G t5;

    printf("%p     %p\n",&t.value1,&t.value2);
    printf("%p     %p\n",&t1.value1,&t1.value2);
    printf("%p     %p\n",&t2.value1,&t2.value2);

    printf("sizeof E = %ld\n",sizeof(struct E)); //12
    printf("%p     %p    %p\n",&t3.value1,&t3.value2,&t3.value3);


     printf("sizeof F = %ld\n",sizeof(struct F)); //12
    printf("%p     %p    %p\n",&t4.value1,&t4.value2,&t4.value3);


     printf("sizeof G = %ld\n",sizeof(struct G)); //12
    printf("%p     %p    %p\n",&t5.value1,&t5.value2,&t5.value3);
    return 0;
}
