#include <iostream>
using namespace std;
class complex
{
private:
    int a;
    int b;
public:
    complex()=default;
    complex(int a,int b):a(a),b(b){}
    ~complex();
    friend complex operator+(const complex &c1,const complex &c2);
};

complex operator+(const complex &c1,const complex &c2)
{
    complex ret = {0,0};
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
    return 0;
}