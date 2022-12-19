#include <iostream>
#include <vector>
using namespace std;

void printVectorInt(int val)
{
    cout << val << " ";
}

int main(int argc, char const *argv[])
{
    vector<int> v;
    v.push_back(100);
    v.push_back(500);
    v.push_back(600);
    v.push_back(200);
    v.push_back(800);
    v.push_back(700);
    v.push_back(300);
    v.push_back(400);

    for_each(v.begin(),v.end(),printVectorInt);
    


    return 0;
}
