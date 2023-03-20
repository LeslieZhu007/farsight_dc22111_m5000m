#include<iostream>
using namespace std;

class parent
{
    protected:
    char* name;
    public:
    parent()
    {
        name = "parent";
    }

    void print()
    {
        cout<<"name:"<<name<<endl;
    }

};

class child:public parent
{
    protected:
    int i;
    public:
    child(int i)
    {
        this->name = "child";
        this->i = i;
    }
};


int main()
{
    child c(1000);
    parent p = c;
    parent *pp = &c;
    parent &rp = c;

    p.print();
    pp->print();
    rp.print();







    return 0;
}