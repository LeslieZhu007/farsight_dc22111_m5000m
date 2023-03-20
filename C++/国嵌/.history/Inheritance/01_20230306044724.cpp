#include<iostream>
using namespace std;

class parent
{
    protected:
    int a;
    public:
    parent()
    {
        a = 1000;
    }

    void print()
    {
        cout<<"a = "<<a<<endl;
    }

};

class child:public parent
{
    private:
    int b;
    public:
    void set(int a,int b)
    {
        this->b = b;
        this->a = a;
    }
};


int main()
{




    return 0;
}