#include <stdio.h>

/**
 * 字节对齐原则
 * 1）32位系统下，所有成员都低于4字节的，按最大的字节对齐，
 *    如果有成员高于4字节，则以4字节对齐   （所有成员种，跟4进行比较，取最小的值）
 * 
 * 2）64位系统下，成员跟8字节进行比较，按最大成员与8相比的最小值进行对齐
 * 
 * 
*/
int main(int argc, char const *argv[])
{
    
    
    return 0;
}
