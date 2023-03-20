#include <iostream>
#include<list>
using namespace std;

int main()
{
    list<double> l;
    cout<<"l.size()="<<l.size()<<endl;

    for (int i = 0; i < 5; i++)
    {
        l.push_back((i+1)/100.0);
    }
    cout<<"l.size()="<<l.size()<<endl;

    list<double>::iterator p = l.begin();
    while (p!=l.end())
    {
        cout<<*p<<endl;
        p++;
    }
    
    p = l.begin();
    l.insert(p,0.389);
    while (p!=l.end())
    {
        cout<<*p<<endl;
        p++;
    }
    
}