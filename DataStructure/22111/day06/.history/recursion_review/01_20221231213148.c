#include <stdio.h>


int fun(int n)
{
    if (n==0)
    {
        return 1;
    } else
    {
        return n*f(n-1);    
    }
    
    
}

int main(int argc, char const *argv[])
{
    printf("%d\n",fun(10));

    return 0;
}
