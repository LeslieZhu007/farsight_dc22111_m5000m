#include<iostream>
using namespace std;

class parent
{
    public:
    parent(const char *s)
    {
        cout<<"parent constructor "<<s<<endl;
    }

    ~parent()
    {
        cout<<"parent destructor"<<endl;
    }

};

class child:public parent
{
    public:
    child(const char* name):parent(name)
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
    child c("jack");
}

int main()
{
    run();
    return 0;
}