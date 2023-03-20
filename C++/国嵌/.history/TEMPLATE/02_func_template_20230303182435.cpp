#include <iostream>
using namespace std;

int max(int a,int b)
{
    return a>b?a:b;
}

template<typename T>
T max(T  a,T  b)
{
    return a>b?a:b;
}

template<typename T>
T max(T  a,T  b,T c)
{
    return a>b?a:b;
}


int main()
{



    return 0;
}