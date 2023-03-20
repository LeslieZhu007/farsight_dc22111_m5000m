#include <iostream>
using namespace std;
struct complex 
{
    int a;
    int b;
};
complex operator+(const complex &c1,const complex &c2)
{
    complex ret;
    ret.a = c1.a + c2.a;
    ret.b = c1.b + c2.b;
    return ret;
}
int main()
{
    complex c1 = {1,2};
    complex c2 = {3,4};
    //complex ret =  operator+(c1,c2);
    complex ret = c1+c2;
    cout<<ret.a<<","<<ret.b<<endl;

}