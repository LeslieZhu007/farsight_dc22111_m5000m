#include<stdio.h>


void fun(int n)
{
    if (n < 10)
    {
        printf("%d\n");
    }else
    {
        fun(n/10);
        printf("%d\n",n%10);
    }
    
}

int main(int argc, char const *argv[])
{
    
    



    return 0;
}
