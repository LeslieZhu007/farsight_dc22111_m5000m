#include <stdio.h>


int func(int x,int n)
{
    if (n == 0)
    {
        return 1;
    } else
    {

    }
    
}

int main(int argc, char const *argv[])
{
    int a = 3;
    int b = 5;
    int c; //c=300
    // c = (a++,b+5,100+200); //运算符优先级  赋
    c = a++,b+5,100+200;
    printf("%d %d %d\n",a,b,c);
    return 0;
}
