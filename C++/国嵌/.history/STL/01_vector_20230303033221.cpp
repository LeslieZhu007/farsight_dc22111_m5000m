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
    v.resize(5);
    cout<<"--------------------"<<endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<endl;
    }
    
    vector<int> v1;
    v1 = v;
    for (int i = 0; i < v1.size(); i++)
    {
        cout<<v1[i]<<endl;
    }




    return 0;
}