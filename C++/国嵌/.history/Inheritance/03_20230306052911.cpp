#include<iostream>
using namespace std;
class object
{
    public:
    object(const char*s)
    {
        cout<<"object constructor"<<" "<<s<<endl;
    }

};

class parent:public object
{
    public:
    parent(const char *s):object(s)
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
    protected:
    object o1;
    object o2;

    public:
    child(const char* name):parent(name),object(name)
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