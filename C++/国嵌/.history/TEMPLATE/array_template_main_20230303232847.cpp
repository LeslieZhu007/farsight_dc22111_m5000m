#include "array_template.cpp"


int main()
{
    Array<int> a(5);
    for (int i = 0; i < a.length(); i++)
    {
        a[i] = i+1;
    }
    
    return 0;
}