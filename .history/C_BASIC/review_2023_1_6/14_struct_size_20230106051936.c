#include <stdio.h>
struct A
{
    char value1;
};

struct B
{
    char value1; //1
    short value2; //2
};

struct C1
{
    char value1; //1
    int value2; //2
};

struct C
{
    char value1; //1
    int value2; //2
    char value3;
};

int main(int argc, char const *argv[])
{
    printf("sizeof(A)=%ld\n",sizeof(struct A)); //1
    printf("sizeof(B)=%ld\n",sizeof(struct B)); //4
    printf("sizeof(C1)=%ld\n",sizeof(struct C1)); //8
    printf("sizeof(C)=%ld\n",sizeof(struct C)); //12
    return 0;
}
