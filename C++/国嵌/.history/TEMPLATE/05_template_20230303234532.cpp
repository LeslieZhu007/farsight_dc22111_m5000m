#include <iostream>
using namespace std;

template<class T>
class Test
{
    public:
    T test(T v)
    {
        cout<<"T test(T v)"<<endl;
        cout<<"sizeof(T)="<<sizeof(T)<<endl;
        return v;
    }

};

template<>
class Test
{
    public:
    T test(T v)
    {
        cout<<"T test(T v)"<<endl;
        cout<<"sizeof(T)="<<sizeof(T)<<endl;
        return v;
    }

};

int main()
{
    Test<int> t1;
    Test<double> t2;
    cout<<t1.test(1)<<endl;
    cout<<t2.test(0.1)<<endl;

}