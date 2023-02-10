#include <stdio.h>

void swap(int *a,int *b)
{
    int temp = *a;
    *b = *a;
    
}

void bubble_sort(int arr[],int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; i < len- i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
    
}

int main(int argc, char const *argv[])
{
    int arr[] = {8,7,6,5,4,3,2};




    return 0;
}
