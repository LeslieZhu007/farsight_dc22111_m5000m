#include<iostream>

using namespace std;

struct TRef
{
    int &a;  //= int * const a;
    int &b;  //= int * const b;
    int &c;
};


int main()
{
    int a = 1,b=2,c=3;
    TRef r = {a,b,c};



    return 0;
}