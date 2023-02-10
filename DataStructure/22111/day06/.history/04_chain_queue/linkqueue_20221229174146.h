#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__
#include <stdio.h>
#include <stdlib.h>
typedef int datatype;

typedef struct Node
{
    union
    {
        datatype data; //普通节点数据域
        int len; //头节点数据域
    };
    struct Node *next;  //指针域
} Node;

typedef struct
{
    Node *head;//存放队列的链表
    Node *tail;//记录队列的尾部
} linkqueue;


//创建
linkqueue * queue_create();


#endif
