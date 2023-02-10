#include <stdio.h>


int fun(int n)
{
    if (n==0)
    {
        return 1;
    } else
    {
        return n*fun(n-1);    
    }
    
    
}

int main(int argc, char const *argv[])
{
    printf("%d\n",fun(5));

    return 0;
}
