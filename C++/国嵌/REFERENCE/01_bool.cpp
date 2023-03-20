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

    a = -5;
    b = a;
    printf("a = %d,b = %d\n",a,b);

    b = 0;
    printf("b = %d\n",b);

    bool a1 = false;
    printf("a1 = %d\n",a1);

    a1++;
    printf("a1 = %d\n",a1);

    a1=a1+1;
    printf("a1 = %d\n",a1);

}