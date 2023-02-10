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

//判空
int queue_empty(linkqueue *L);

//入队
void queue_push(linkqueue *L,datatype e);
//遍历
void queue_show(linkqueue *L);

//出队
void queue_pop(linkqueue *L);
//求返回队列长度
int queue_size(linkqueue *L);

//销毁
void queue_free(linkqueue *L);
#endif
