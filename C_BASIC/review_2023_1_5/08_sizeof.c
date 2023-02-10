#include <stdio.h>


int main(int argc, char const *argv[])
{
    int a = 520;
    //printf("%ld\n",sizeof(++a)); //sizeof 编译的时候已经执行，运算还未开始 
    //不参与运算，不关心语句，只关心数据类型
    printf("%ld\n",sizeof(++a + 100));
    //sizeof(++a); 

    printf("a = %d\n",a);  //520
    
    return 0;
}
