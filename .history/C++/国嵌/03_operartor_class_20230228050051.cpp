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
    return 0;
}