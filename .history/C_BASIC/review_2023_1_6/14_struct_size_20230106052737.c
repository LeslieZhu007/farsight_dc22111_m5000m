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
    int value2; //4
    char value3; //1
};

struct C2
{
    char value1; //1
    char value2; //1
    int value3; //4
};

struct D
{
    char value1; //1
    int *p; //8
};

struct E
{
    int value1; //4
    char value2; //1
    short value3; //2
};

struct F
{
    int value1; //4
    int  *p; //8
    char value2; //1
};


struct G
{
    short value1; //4
    char value2; //1
    short value3;
    int value4;
    double value5;
    int value6;
};



int main(int argc, char const *argv[])
{
    printf("sizeof(A)=%ld\n",sizeof(struct A)); //1
    printf("sizeof(B)=%ld\n",sizeof(struct B)); //4
    printf("sizeof(C1)=%ld\n",sizeof(struct C1)); //8
    printf("sizeof(C)=%ld\n",sizeof(struct C)); //12
    printf("sizeof(C2)=%ld\n",sizeof(struct C2));
    printf("sizeof(D)=%ld\n",sizeof(struct D));
    printf("sizeof(E)=%ld\n",sizeof(struct E));
    printf("sizeof(F)=%ld\n",sizeof(struct F));
    return 0;
}
