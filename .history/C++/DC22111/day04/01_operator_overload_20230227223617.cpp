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
};

complex::complex(int real,int image):real(real),image(image)
{
}

complex::~complex()
{
}


int main()
{
    /* code */
    return 0;
}
