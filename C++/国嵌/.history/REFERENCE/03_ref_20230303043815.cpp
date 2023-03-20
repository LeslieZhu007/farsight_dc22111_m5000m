#include<iostream>

using namespace std;


int main()
{
    int a = 10;
    int &b = a;
    b = 5;
    printf("a=%d\n",a);
    printf("b=%d\n",b);

    printf("a=%08X\n",&a);
    printf("b=%08X\n",&b);



    return 0;
}