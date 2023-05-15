#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void Test01(void)
{
    char *str = (char *) malloc(100);
    strcpy(str,"hello");
    free(str);
    if (str!=NULL)
    {
        strcpy(str,"world");
        printf(str);
    }
    
}

int main(int argc, char const *argv[])
{
    
    
    //Test();
    Test01();



    
    return 0;
}
