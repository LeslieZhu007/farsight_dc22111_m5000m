#include<iostream>

using namespace std;


int main()
{
    int a = 10;
    int &b = a;
    b = 5;
    printf("a=%d\n",a);
    printf("b=%d\n",b);

    printf("a=%p\n",&a);
    printf("b=%p\n",&b);



    return 0;
}