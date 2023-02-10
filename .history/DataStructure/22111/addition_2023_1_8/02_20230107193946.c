#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char str[] = {'a', 'b', 'c'};
    printf("sizeof str = %ld\n",sizeof(str));
    printf("strlen str = %ld\n",strlen(str));
    return 0;
}
