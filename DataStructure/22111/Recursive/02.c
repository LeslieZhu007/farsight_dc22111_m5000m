#include <stdio.h>
/*
    输入一个数，正序输入该数的每一位
    递归实现
*/

void recursive_fun(int n)
{
   if (n < 10)
   {
        printf("%d\t",n);
   } else
   {
        recursive_fun(n/10); //输出前面的数据
        printf("%d\t",n%10);  //输出当前数据的最后一位
   }
   
}

int main(int argc,const char* argv[])
{
    recursive_fun(2567);
   
}