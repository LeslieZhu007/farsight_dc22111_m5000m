#include <stdio.h>

/**
 * 字节对齐原则
 * 1）32位系统下，所有成员都低于4字节的，按最大的字节对齐，
 *    如果有成员高于4字节，则以4字节对齐   （所有成员种，跟4进行比较，取最小的值）
 * 
 * 2）64位系统下，成员跟8字节进行比较，按最大成员与8相比的最小值进行对齐
 * 
 * 3）整体也要进行字节对齐，32位4字节对齐，也就是说32位系统下，结构体最终的大小要是4的倍数
 *    64位系统下，如果没有超过4个字节的，最终结果是4的倍数，如果有8字节的成员，最终结果是8的倍数
*/

struct A
{
    char value1; //1
};

struct B
{
    char value1; //1
    short value2; //2
};

struct C
{
    char value1; //1
    int  value2; //2 ==>12
    char value3; //1
};
int main(int argc, char const *argv[])
{
    printf("size of A = %ld\n",sizeof(struct A)); //1
    printf("size of B = %ld\n",sizeof(struct B)); //4
    printf("size of C = %ld\n",sizeof(struct C)); //4

    
    struct B t;
    printf("%p    %p\n",&t.value1,&t.value2);
    
    
    return 0;
}
