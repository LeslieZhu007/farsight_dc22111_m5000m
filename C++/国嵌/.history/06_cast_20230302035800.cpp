#include <iostream>
using namespace std;
class Test
{
private:
    int i;
public:
    Test(){cout<<"Test()"<<endl;i=0;}
    Test(int i):i(i){cout<<"Test(int i)"<<endl;}
    ~Test(){cout<<"~Test"<<endl;}
    int geti()
    {
        return this->i;
    }

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
    cout<<p1->geti()<<" "<<p2->geti()<<endl;
    free(p1);
    delete p2;
}

int main()
{
    func();


    return 0;
}