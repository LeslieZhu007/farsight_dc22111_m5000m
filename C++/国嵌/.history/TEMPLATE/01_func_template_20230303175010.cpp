#include <iostream>
using namespace std;

template <typename T>
void swap1(T& a,T& b)
{
    T temp = b;
    b = a;
    a = temp;
}

int main()
{
    int a = 3;
    int b = 4;
    swap1<int>(a,b);
    cout<<a<<b<<endl;



    return 0;
}