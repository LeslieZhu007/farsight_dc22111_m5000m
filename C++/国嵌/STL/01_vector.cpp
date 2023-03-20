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


    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<endl;
    }
    cout<<"--------------------"<<endl;
    vector<int> v1;
    v1 = v;
    v.resize(0);
    for (int i = 0; i < v1.size(); i++)
    {
        cout<<v1[i]<<endl;
    }

cout<<"--------------------"<<endl;
    vector<int> v2 = {6,7,8,9,10};
    for (int i = 0; i < v2.size(); i++)
    {
        cout<<v2[i]<<endl;
    }
    return 0;
}