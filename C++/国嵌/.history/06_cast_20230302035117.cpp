#include <iostream>
using namespace std;

void func()
{
    int *p =reinterpret_cast<int *> (malloc(sizeof(int)));
    int *q = new int(10);
    *p = 5;
    cout<<*p<<" "<<*q<<endl;
    delete q;
    free(p);
}

int main()
{
    func();


    return 0;
}