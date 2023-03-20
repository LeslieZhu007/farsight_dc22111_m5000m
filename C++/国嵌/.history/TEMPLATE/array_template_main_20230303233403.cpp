#include "array_template.hpp"  //==> 不能直接包含.h文件


int main()
{
    Array<int> a(5);
    for (int i = 0; i < a.length(); i++)
    {
        a[i] = i+1;
    }

    for (int i = 0; i < a.length(); i++)
    {
        cout<<a[i]<<endl;
    }

    Array<double> a(10);
    for (int i = 0; i < a.length(); i++)
    {
        a[i] = i+1;
    }

    for (int i = 0; i < a.length(); i++)
    {
        cout<<a[i]<<endl;
    }
    
    return 0;
}