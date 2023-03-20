#include<iostream>
using namespace std;

class parent
{
    protected:
    int i;
    int f;
};

class child:public parent
{
    protected:
    int i;
    void f()
    {
        cout<<"parent::i="<<parent::i<<endl;
        cout<<"child::i="<<child::i<<endl;
        cout<<"parent::f="<<parent::f<<endl;
    }
    public:
    child(int i,int j)
    {
        parent::i = i;
        child::i = j;
        parent::f = i+j;
        f();
    }
};

void run()
{
    child c(1,3);
}


int main()
{
    run();

}