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
    ~complex(){}
    complex operator+(const complex &c2);
    //ostream& operator<<(ostream& out,const complex& c);
    void show();
};

void complex::show()
{
    cout<<"a="<<a<<","<<"b="<<b<<endl;
}

complex complex::operator+(const complex &c2)
{
    complex temp(0,0);
    temp.a = this->a + c2.a;
    temp.b = this->b + c2.b;
    return temp;
}


int main()
{
    complex c1 = {1,2};
    complex c2 = {3,4};
    //complex ret =  operator+(c1,c2);
    complex ret = c1+c2;
    ret.show();
    //operator<<(cout,c1);
    cout<<c1<<endl;
    cout<<c2<<endl;
    cout<<ret<<endl;
    return 0;
}