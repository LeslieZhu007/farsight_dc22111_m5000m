#include <iostream>
using namespace std;

class complex
{
private:
     int real,image;
public:
    complex(int real,int image);
    ~complex();
    friend const complex operator+(const complex &L,const complex &R);
    friend bool operator>(const complex &L,const complex &R);
    friend const complex operator+=(complex &L,const complex &R);
    //单目运算符
    friend const complex operator-(const complex &R);
};

complex::complex(int real,int image):real(real),image(image)
{
}

complex::~complex()
{
}

const complex operator+(const complex &L,const complex &R)
{

}
bool operator>(const complex &L,const complex &R)
{

}
const complex operator+=(complex &L,const complex &R)
{

}
//单目运算符
const complex operator-(const complex &R)
{
    
}


int main()
{
    /* code */
    return 0;
}
