#include <iostream>

using namespace std;
/*
 *  编写函数，获取数组指定元素的内容
 */

int getArray(int a[],int len,int n)
{
    if(n < 0 || n > len - 1)
    {
        throw 0;
    } else
    {
        return a[n];
    }
}

void test4()
{
    int arr[] = {100,20,5,33,89,66,91,73,52};
    int num;
    try {
        num = getArray(arr,sizeof(arr)/sizeof(int),20);
        cout << num << endl;
    }  catch (int &e) {
        if(e==0)
        {
            cout<<"array index out of bounds"<<endl;
        }
    }
}


int main()
{
    cout << "Hello World!" << endl;
    //test1();
    //test2();
    //test3();
    test4();
    return 0;
}
