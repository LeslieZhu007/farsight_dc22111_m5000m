#include <iostream>
using namespace std;

class complex
{
private:
     int real,image;
public:
    void show()
    {
        cout<<real<<","<<image<<endl;
    }
    complex()=default;
    complex(int real,int image);
    ~complex();
    friend const complex operator+(const complex &L,const complex &R);
    friend bool operator>(const complex &L,const complex &R);
    friend const complex operator+=(complex &L,const complex &R);
    //单目运算符
    friend const complex operator-(const complex &R);
    //前置自增和后置自增的类外写法
    friend const complex& operator++(complex &O,void);
    friend const complex operator++(complex &O,int);
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

// 前置++
const complex& operator++(complex &O,void)
{
    ++O.real;
    ++O.image;
    return O;
}

//后置++  
const complex operator++(complex &O,int)
{
    complex temp;
    temp.real = O.real++;
    temp.image = O.image++;
    return temp;
}


int main()
{
    complex c1(1,2),c3(3,4),c2;
    ++c1;
    c1.show();

    

    return 0;
}
