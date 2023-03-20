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

    printf("&a = %p\n",&a);
    printf("&b = %p\n",&b);
    printf("&c = %p\n",&c);



    return 0;
}