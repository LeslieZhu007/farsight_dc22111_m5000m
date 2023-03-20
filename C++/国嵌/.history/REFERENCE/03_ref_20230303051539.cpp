#include<iostream>

using namespace std;

struct TRef
{
    int &a;  //= int * const a;
    int &b;  //= int * const b;
    int &c;
};

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
    b = t;
}


int main()
{
    //int a = 10;
    const int &b = 1;
    //b = 5;
    int *p = (int *)&b;
    *p = 5;
    //printf("a=%d\n",a);
    printf("b=%d\n",b);

    //printf("a=%p\n",&a);
    printf("b=%p\n",&b);

    int c = 4;
    int d = 5;
    cout<<c<<","<<d<<endl;
    swap(c,d);
    cout<<c<<","<<d<<endl;

    cout<<sizeof(TRef)<<endl;

    TRef r = {a,b,c}


    return 0;
}