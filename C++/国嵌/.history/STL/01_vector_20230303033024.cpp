#include<iostream>
#include<vector>
using namespace std;


int main()
{
    vector<int> v(10);
    cout<<"v.size()="<<v.size()<<endl;   //0
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