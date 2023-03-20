#include<iostream>

using namespace std;

int main()
{
    int a;
    bool b = true;
    printf("b = %d,sizeof(b) = %ld\n",b,sizeof(b));

    b = 3;
    a = b;
    printf("a = %d,b = %d\n",a,b);

    b = -5;
    a = b;
    printf("a = %d,b = %d\n",a,b);

    
}