#include <iostream>
using namespace std;
class Test
{
private:
    int i;
public:
    Test(){cout<<"Test()"<<endl;i=0}
    Test(int i):i(i){cout<<"Test(int i)"<<endl;}
    ~Test(){cout<<"~Test"<<endl;}

};

void func()
{
    int *p =reinterpret_cast<int *> (malloc(sizeof(int)));
    int *q = new int(10);
    *p = 5;
    cout<<*p<<" "<<*q<<endl;
    delete q;
    free(p);

    Test *p1 = reinterpret_cast<Test *> (malloc(sizeof(Test)));
    Test *p2 = new Test(1);
}

int main()
{
    func();


    return 0;
}