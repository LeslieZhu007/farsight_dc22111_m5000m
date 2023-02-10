#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a,b,c,abc=0;
    a=b=c=40;
    if (c)
    {
        int abc = 10;
        abc = a*b+c++;
    }
    printf("%d,%d",abc,c);
    return 0;
    

    return 0;
}
