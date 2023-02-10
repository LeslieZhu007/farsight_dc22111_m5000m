#include <stdio.h>


int main(int argc, char const *argv[])
{
    printf("hello world--1\n");
    goto NEXT;
    printf("hello world--2\n");
NEXT:
    printf("hello world--3\n");
NEXT1:
    printf("hello world--4\n");
    printf("hello world--5\n");

    return 0;
}
