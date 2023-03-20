#include<iostream>

using namespace std;


int main()
{
    int a = 10;
    int &b = a;
    b = 5;
    printf("a=%d\n",a);
    printf("b=%d\n",b);

    printf("a=%x08\n",&a);
    printf("b=%x08\n",&b);



    return 0;
}