#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<int> v(10);
    for (int i = 0; i < v.size(); i++)
    {
        v[i] = i;
    }

    for(int i:v)
    {
        cout<<i<<endl;
    }
    

}