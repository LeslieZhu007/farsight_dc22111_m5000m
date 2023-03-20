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
    }
};


int main()
{




    return 0;
}