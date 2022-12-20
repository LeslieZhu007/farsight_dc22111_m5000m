#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <stdio.h>
#define MAX 20
typedef int datatype;

/*
1. MAX表示容器的最大容量
2. len表示当前顺序表的元素个数，也就是数组中使用的元素个数
3. len还能表示在数组中第一个没有存储数据元素数组元素下标
4. 顺序表长度len<=数组长度MAX
5. 顺序表存储数据有上限，当元素达到数组长度后，便不能再存储新元素了

*/
struct seqList
{
    datatype data[MAX];     //存储顺序表的数组
    int len;                //顺序表的实际长度
};

//插入


//删除


//修改


//查找





#endif