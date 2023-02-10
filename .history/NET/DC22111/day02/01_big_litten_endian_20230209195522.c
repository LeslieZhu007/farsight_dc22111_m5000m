#include <stdio.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    int a = 0x12345678;
    char *p = (char *)&a;
    for (int i = 0; i < strlen(p); i++)
    {
        printf("%d\n",p[i]-49);
    }
    
    




    return 0;
}
