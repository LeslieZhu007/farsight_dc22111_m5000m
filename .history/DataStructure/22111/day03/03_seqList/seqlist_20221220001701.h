#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
typedef int datatype;

/*
    1. MAX表示容器的最大容量
    2. len表示当前顺序表的元素个数，也就是数组中使用的元素个数
    3. len还能表示在数组中第一个没有存储数据元素数组元素下标
    4. 顺序表长度len<=数组长度MAX
    5. 顺序表存储数据有上限，当元素达到数组长度后，便不能再存储新元素了
*/
typedef struct 
{
    datatype data[MAX];     //存储顺序表的数组
    int len;                //顺序表的实际长度
} seqList;

//创建顺序表
seqList *list_create();

//判空
int list_empty(seqList *L);

//判满
int list_full(seqList *L);

//添加元素   表尾 尾插
int list_add(seqList *L,datatype e);

//遍历
void list_show(seqList *L);

//任意位置插入 ==
int list_insert_pos(seqList *L,int pos,datatype e);

//任意位置删除 ==

//按位置修改

//按值修改

//按位置查找返回元素

//按值查找返回位置

//顺序表排序

//顺序表去重

//顺序表释放

#endif