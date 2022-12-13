#include <stdio.h>

int main(int argc, char const *argv[])
{
    
    int a[3][3] ={1,2,3,4,5,6,7,8,9};
    //a[0]: 第一行的第一个地址 a[0] = &a[0][0]  a[1] = &a[1][0]
    //a[1]: 第二行的第一个地址
    printf("a[0]=%p\na[1]=%p\n,&a[0]+1=%p\n",a[0],a[1],&a[0]+1);

     printf("a[1]=%p\na[2]=%p\n,&a[1]+1=%p\n",a[1],a[2],&a[1]+1);

    printf("&a[0][0]=%p\n&a[0][1]=%p\n&a[0][0]+1=%p\n",&a[0][0],&a[0][1],&a[0][0]+1);

    printf("a=%p\na+1=%p\n",a,a+1);

    printf("=======================================================\n");
    int i,j;
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            //printf("a=[%d][%d]=%d\n",i,j,a[i][j]);
            printf("a[%d][%d]=%d\n",i,j,*(*(a+i)+j));
        }
    }

    printf("a[1][2]=%d\n",*(*(a+1)+2));
    
    return 0;
}
