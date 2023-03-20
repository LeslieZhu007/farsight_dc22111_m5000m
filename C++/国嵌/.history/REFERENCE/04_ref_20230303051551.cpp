#include<iostream>

using namespace std;

struct TRef
{
    int &a;  //= int * const a;
    int &b;  //= int * const b;
    int &c;
};