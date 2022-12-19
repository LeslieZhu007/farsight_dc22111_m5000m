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

int main(int argc, char const *argv[])
{
    printf("sizeof A = %ld\n",sizeof(struct A));
    

    return 0;
}
