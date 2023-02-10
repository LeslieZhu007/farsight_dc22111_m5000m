#include <stdio.h>

void swap(int *a,int *b)
{
    int temp = *b;
    *b = *a;
    *a =temp;
    
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
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
