#include <stdio.h>

void bubble_sort(int *arr,int n)
{
    for (int i = 1; i < n; i++) //外层循环控制趟数
    {
        for (int j = 0; j < n-i; j++) //内存循环控制元素，交换次数
        {
            if (arr[j] > arr[j+1]) //控制升降序
            {
                //交换
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            
        }
        
    }
    printf("排序成功\n");
}

void bubble_sort_improve(int *arr,int n)
{
    for (int i = 1; i < n; i++) //外层循环控制趟数
    {
        int flag = 0; //在当前趟排序之前定义旗帜
        for (int j = 0; j < n-i; j++) //内存循环控制元素，交换次数
        {
            if (arr[j] > arr[j+1]) //控制升降序
            {
                //交换
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

                flag = 1;
            }
        
        }
            //对flag进行判断，判断当前趟的排序是否进行了交换数据
            if (flag == 0)
            {
                break;  //中止剩余的排序趟数
            }
            
        
    }
    printf("排序成功\n");
}


void select_sort(int *arr,int n)
{
    for (int i = 0; i < n; i++) //表示待排序序列的第一个元素
    {
        int min = i; //将待排序序列的第一个元素下标当作最值
        for (int j = i+1; j < n; j++)  //遍历待排序序列，找到最小值所在下标
        {
            if (arr[min] > arr[j])  //拿着当前记录的最值
            {
                min = j; //更新最小值所在下标
            }
            
        }
        //判断找到的最小值是否是待排序序列的第一个元素
        if (min != i)
        {
            //交换
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    printf("选择排序成功\n");
    
}


void insert_sort(int *arr,int n)
{
    for (int i = 1; i < n; i++)  //从第二个元素开始  i表示待排序序列的第一个元素
    {
        int j;
        int temp = arr[i]; //记录要进行插入的数据
        for (j = i; arr[j-1]>temp&&j>0; j--) //拿着要插入的数据，向前遍历，直到找到比自己小的数据为止
        {
            arr[j] = arr[j-1]; //将前面的元素不断后移
        }
        //将元素放入空中
        arr[j] = temp;
        printf("插入排序成功\n");
    }
    




}


int main(int argc, char const *argv[])
{
    int arr[] = {2,8,1,6,3,7,4,5};
    int len = sizeof(arr)/sizeof(arr[0]); //求数组长度

    //调用冒泡排序函数
    /*
    bubble_sort_improve(arr,len);

    printf("冒泡排序后的结果为: ");
    for (int i = 0; i < len; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    */

   /*
    select_sort(arr,len);
     printf("选择排序后的结果为: ");
    for (int i = 0; i < len; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    */

   insert_sort(arr,len);
     printf("插入排序后的结果为: ");
    for (int i = 0; i < len; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
    return 0;
}
