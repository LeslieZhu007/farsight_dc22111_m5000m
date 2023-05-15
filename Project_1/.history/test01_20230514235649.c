#include <stdio.h>


void GetMemory(char *p)
{
    p = (char *)malloc(100);
}

void Test(void)
{
    char *str = NULL;
    GetMemory(str);
    strcpy(str,"hello world");
    printf(str);
}

int main(int argc, char const *argv[])
{
    
    
    Test();




    
    return 0;
}
