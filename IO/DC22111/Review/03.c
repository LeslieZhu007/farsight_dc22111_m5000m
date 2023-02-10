#include <stdio.h>

int main(int argc, char const *argv[])
{
    char str[32] = "hello world";
    for(int i = 0;i < sizeof(str);i++)
    {
        printf("%c %d\n",str[i],str[i]);
    }
    return 0;
}
