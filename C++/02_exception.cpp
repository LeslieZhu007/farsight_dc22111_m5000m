#include <iostream>

using namespace std;
/*
 *  编写函数，获取数组指定元素的内容
 */

int getArray(int a[],int len,int n)
{
    if(n < 0 || n > len - 1)
    {
        throw out_of_range("数组元素访问越界");
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
    }  
    catch (exception &e) 
    {
        //exception 为总的异常类
        cout<<e.what()<<endl;
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
