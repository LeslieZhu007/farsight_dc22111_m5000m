#include <stdio.h>

//定义折半查找函数
int half_search(int *arr,int n,int key)
{
    int low = 0;
    int high = n-1;
    while (low <= high)
    {
        int mid = (low + high)/2; //找到中间元素下标
        if (arr[mid] == key)
        {
            return mid; //找到对应元素，将元素下标返回
        } else if (key > arr[mid])
        {
            low = mid + 1; //舍弃前面一半元素
        } else if (key < arr[mid])
        {
            high = mid - 1; //舍弃后面一半元素
        }
    }
    return -1; //表明没找到
}


int main(int argc, char const *argv[])
{
    int arr[] = {2,5,7,9,11,15,27};
    int len = sizeof(arr)/sizeof(arr[0]);
    
    int result = half_search(arr,len,15);
    if (result < 0)
    {
        printf("没找到\n");
    } else
    {
         printf("result = %d\n",result);
    }
    


    return 0;
}
