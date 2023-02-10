#include <stdio.h>
static int count=0;

int fun(int n)
{
    printf("第%d次进入fun,n=%d\n",count+1,n);
    count++;
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
