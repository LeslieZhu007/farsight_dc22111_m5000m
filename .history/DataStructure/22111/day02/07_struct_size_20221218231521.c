#include <stdio.h>

struct A
{
    int value1;   //4
    char value2;  //1   ==>
    short value3; //2
};

struct B
{
    int value1;   //4
    int *p;       //8
    char value2;  //1
};


struct C
{
    short value1;   //4  
    char value2;  //1
    short value3;
    int value4;
    double value5;
};




int main(int argc, char const *argv[])
{
    printf("sizeof A = %ld\n",sizeof(struct A)); //8
    printf("sizeof A = %ld\n",sizeof(struct A)); //
    printf("sizeof A = %ld\n",sizeof(struct A));
    
    return 0;
}
