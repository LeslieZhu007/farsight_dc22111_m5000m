#include <iostream>
using namespace std;

int max(int a,int b)
{
    cout<<"max(int a,int b)"<<endl;
    return a>b?a:b;
}

template<typename T>
T max(T  a,T  b)
{
    cout<<"T max(T  a,T  b)"<<endl;
    return a>b?a:b;
}

template<typename T>
T max(T  a,T  b,T c)
{
    cout<<"T max(T  a,T  b,T c)"<<endl;
    return max(max(a,b),c);
}


int main()
{
    int a = 1;
    int b  =2 ;
    cout<<max(a,b)<<endl;
    cout<<max<>(a,b)<<endl;

    cout<max(3.0,4.0)<<endl;


    return 0;
}