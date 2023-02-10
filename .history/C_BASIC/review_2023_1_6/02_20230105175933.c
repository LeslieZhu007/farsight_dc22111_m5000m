#include <stdio.h>

char* GetMemory(void)
{
    char p[] = "hello world";
    return p;
}

int main(int argc, char const *argv[])
{
    char *str = NULL;
    str = GetMemory();
    printf(str);
    printf("hekko\n");
    return 0;
}
