#ifndef __LINKLIST_H__
#define __LINKLIST_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char datatype;

//定义节点结构体
typedef struct Node
{
    union 
    {
        datatype data; //普通节点数据域
        int len; //头节点数据域
    };
    struct Node *next;  //指向下一个节点的指针
} *LinkList,Node;

//创建链表
LinkList list_create();

//判空
int list_empty(LinkList L);

//头插


//遍历

//尾插

//任意位置插入

//头删

//尾删

//任意删


#endif