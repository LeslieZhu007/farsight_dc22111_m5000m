#include <iostream>
using namespace std;

int Max(int a,int b)
{
    cout<<"Max(int a,int b)"<<endl;
    return a>b?a:b;
}

template<typename T>
T Max(T  a,T  b)
{
    cout<<"T Max(T  a,T  b)"<<endl;
    return a>b?a:b;
}

template<typename T>
T Max(T  a,T  b,T c)
{
    cout<<"T Max(T  a,T  b,T c)"<<endl;
    return Max(Max(a,b),c);
}

template<typename T1,typename T2,typename T3)


int main()
{
    int a = 1;
    int b  =2;
    cout<<Max(a,b)<<endl;
    cout<<Max<>(a,b)<<endl;

    cout<<Max(3.0,4.0)<<endl;

    cout<<Max(3.0,4.0,5.0)<<endl;

    cout<<Max('a',100)<<endl;


    return 0;
}