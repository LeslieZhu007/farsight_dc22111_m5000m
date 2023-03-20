#include <iostream>
using namespace std;

template<class T>
class Operator
{
    public:
       T add(T a,T b);

       T minus(T a,T b);
};

template<class T>
T Operator<T>::add(T a,T b)
{
    return a+b;
}

template<class T>
T Operator<T>::minus(T a,T b)
{
    return a-b;
}


int main()
{
    Operator<int> op1;
    Operator<double> op2;
    cout<<op1.add(5,4)<<endl;
    cout<<op1.minus(5,4)<<endl;

    cout<<op2.add(5,4)<<endl;
    cout<<op2.minus(5,4)<<endl;



    return 0;
}