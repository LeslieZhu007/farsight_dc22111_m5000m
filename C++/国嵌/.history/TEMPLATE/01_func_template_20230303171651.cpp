#include <iostream>
using namespace std;

template <class T>
void swap(T a,T b)
{
    T temp = b;
    b = a;
    a = temp;
}

int main()
{
    int a = 3;
    int b = 4;
    swap<float>(3,4);
    cout<<a<<b<<endl;



    return 0;
}