#include<iostream>
#include<vector>
using namespace std;


int main()
{
    vector<int> v;
    for (int i = 0; i < 5; i++)
    {
        v[i] = i+1;
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<endl;
    }
    
    




    return 0;
}