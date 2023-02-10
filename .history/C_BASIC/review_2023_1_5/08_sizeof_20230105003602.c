#include <stdio.h>


int main(int argc, char const *argv[])
{
    int a = 520;
    printf("%ld\n",sizeof(++a));

    printf("a = %d\n",a);
    
    return 0;
}
