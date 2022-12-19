#include <stdio.h>

struct A
{
    int value1;   //4
    char value2;  //1   ==>8
    short value3; //2
};

struct B
{
    int value1;   //4
    int *p;       //8   ==>24
    char value2;  //1
};


struct C
{
    short value1;   //2  
    char value2;  //1
    short value3; //2
    int value4;  //4
    double value5;  //8
    int value6; //4
};

struct D
{
    char s[5]; //

};


struct E
{
    int value1; //4
    char s[5];  //5
};   //12


struct F
{
    int value1; //4
    char s[5];   //5
    char value2;  //1
};  //12


struct F
{
    int value1; //4
    char s[5];   //5
    short value2;  //1
};  //12

struct G
{
    int value1; //4
    char s[5];   //5
    short value2;  //1
    double value3;
};  //12


struct H
{
    int value1; //4
    struct E e; //
};  //

int main(int argc, char const *argv[])
{
    printf("sizeof A = %ld\n",sizeof(struct A)); //8
    printf("sizeof B = %ld\n",sizeof(struct B)); //24
    printf("sizeof C = %ld\n",sizeof(struct C)); //24

    printf("sizeof D = %ld\n",sizeof(struct D)); //24
    return 0;
}
