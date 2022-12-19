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

int main(int argc, char const *argv[])
{
    printf("sizeof A = %ld\n",sizeof(struct A)); //1
    printf("sizeof B = %ld\n",sizeof(struct B)); //4
    printf("sizeof C = %ld\n",sizeof(struct C)); //8

    struct C t;
    struct B t1;
    printf("%p     %p\n",&t.value1,&t.value2);
    printf("%p     %p\n",&t1.value1,&t1.value2);

    return 0;
}
