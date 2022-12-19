#include <stdio.h>
#include <string.h>

struct A
{
    char value1;
};

int main(int argc, char const *argv[])
{
    printf("sizeof A = %ld\n",sizeof(struct A));
    

    return 0;
}
