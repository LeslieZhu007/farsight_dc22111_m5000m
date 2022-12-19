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
    int value2; //2
    char value3;
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
    

    printf("%p     %p\n",&t.value1,&t.value2);
    printf("%p     %p\n",&t1.value1,&t1.value2);
    printf("%p     %p\n",&t2.value1,&t2.value2);

    printf("sizeof E = %ld\n",sizeof(struct E)); //12
    printf("%p     %p    %p\n",&t3.value1,&t3.value2,&t3.value3);
    return 0;
}
