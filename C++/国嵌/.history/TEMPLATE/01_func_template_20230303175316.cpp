#include <iostream>
using namespace std;

template <typename T>
void swap1(T& a,T& b)
{
    T temp = b;
    b = a;
    a = temp;
}

template <typename T>
void select_sort(T array[],int length)
{
    for (int i = 0; i < length; i++)
    {
        T min = array[i];
        int index = i;
        for (int j = i+1; j < length; j++)
        {
            if (array[j]<min)
            {
                min = array[j];
                index = j;
            }
            
        }
        
    }
    
}


int main()
{
    int a = 3;
    int b = 4;
    swap1<int>(a,b);
    cout<<a<<b<<endl;



    return 0;
}