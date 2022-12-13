#include <stdio.h>

//数组指针
//作用：主要用在二维数组传参
//p 就等价于二维数组名
//int a[2][3] = {1,2,3,4,5,6};
//int (*p)[3] = a; 表示定义一个指针，在遍历时，3个一行
//int (*q)[3]; q=a;

int fun(int (*p)[4],int line,int row)

{
    int i,j;
    int max,count = 0;
    for ( i = 0; i < line; i++)
    {
        for ( j = 0; j < row; j++)
        {
            count++;
            if (count==1)
            {
                //max= *(*(p+i)+j) ;
                max= *(p[i]+j) ;
            }
            
            
            if (max <*(*(p+i)+j) )
            {
                //max=*(*(p+i)+j);
                max= *(p[i]+j) ;
            }
            
            
        }
        
    }

    return max;
    
}

int main(int argc, char const *argv[])
{
    //计算二维数组最大值
    int a[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int (*p)[4] = a;
    int line = sizeof(a)/sizeof(a[0]);
    int row = sizeof(a[0])/sizeof(int);
    int n = sizeof(a)/sizeof(int);
    printf("line = %d\n",line);
    printf("row = %d\n",row);
    printf("n = %d\n",n);

    int max = fun(p,line,row);

    printf("max = %d\n",max);
    
    
    return 0;
}
