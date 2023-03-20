#include<iostream>

using namespace std;

void swap(int*pa,int*pb)
{
    int t = *pa;
    *pa=*pb;
    *pb = t;
}

void swap(int&a,int&b)
{
    int t = a;
    a = b;
    b = a;
}


int main()
{
    int a = 10;
    int &b = a;
    b = 5;
    printf("a=%d\n",a);
    printf("b=%d\n",b);

    printf("a=%p\n",&a);
    printf("b=%p\n",&b);



    return 0;
}