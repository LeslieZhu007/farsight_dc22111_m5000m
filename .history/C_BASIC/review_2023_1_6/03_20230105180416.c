#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void GetMemory(char *p)
{
    p = (char *)malloc(100);
}

int main(int argc, char const *argv[])
{
    char *str = NULL;
    GetMemory(str);
    strcpy(str,"hello world");
    printf("%s",str);
    //printf("hekko\n");
    return 0;
}
