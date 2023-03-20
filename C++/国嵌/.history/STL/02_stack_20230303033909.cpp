#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

void stackuseage()
{
    cout<<"stack usage"<<endl;
    stack<double> s;
    for (int i = 0; i < 5; i++)
    {
        s.push(i/100.0);
    }

    while (!s.empty())
    {
        double v= s.top();
        s.pop();
        cout<<v<<endl;
    }
    
    
}

int main()
{
    stackuseage();

}