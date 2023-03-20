#include<iostream>

using namespace std;

int &f()
{
    static int a = 0;
    return a;
}

int &g()
{
    int a = 0;
    return a;
}


int main()
{
    int a = g();
   //int& b= g();
    f() = 10;

    cout<<"a = "<<a<<endl;
   // cout<<"b = "<<b<<endl;
    cout<<"f() = "<<f();

}