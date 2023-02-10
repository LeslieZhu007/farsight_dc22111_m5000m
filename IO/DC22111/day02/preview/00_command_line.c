#include <stdio.h>

int main(int argc, char const *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        printf("%s ",argv[i]);
    }
    printf("\n");
    return 0;
}
