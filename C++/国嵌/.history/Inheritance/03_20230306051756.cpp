#include<iostream>
using namespace std;

class parent
{
    public:
    parent()
    {
        cout<<"parent constructor"<<endl;
    }

    ~parent()
    {
        cout<<"parent destructor"<<endl;
    }

};

class child:public parent
{
    public:
    child()
    {
        cout<<"child constructor"<<endl;
    }

    ~child()
    {
        cout<<"child destructor"<<endl;
    }

};

void run()
{
    child c;
}

int main()
{
    run();
    return 0;
}