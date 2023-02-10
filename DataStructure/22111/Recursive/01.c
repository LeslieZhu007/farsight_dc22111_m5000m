#include <stdio.h>

int recursive_fun(int n)
{
    if(n==0)
    {
        return 1;
    } else
    {
        return n*recursive_fun(n-1);
    }
}

int main(int argc,const char* argv[])
{
    int ret = recursive_fun(5);
    printf("ret = %d\n",ret);
}