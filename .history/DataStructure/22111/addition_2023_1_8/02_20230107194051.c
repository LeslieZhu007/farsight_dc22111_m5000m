#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    char str[] = {'a', 'b', 'c'};
    printf("sizeof str = %ld\n",sizeof(str));
    printf("strlen str = %ld\n",strlen(str));

    char str1[7] = "abc123";
    printf("sizeof str1 = %ld\n",sizeof(str1));
    printf("strlen str1 = %ld\n",strlen(str1));
    return 0;
}
