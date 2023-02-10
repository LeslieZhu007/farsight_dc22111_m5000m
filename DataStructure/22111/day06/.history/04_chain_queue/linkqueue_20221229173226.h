#ifndef __LINKQUEUE_H__
#define __LINKQUEUE_H__

typedef int datatype;

typedef struct Node
{
    union
    {
        datatype data; //数据域
        int len; //头节点数据域
    };
    struct Node *next;  //指针域
} Node;

typedef struct
{
    Node *head;//存放队列的链表
    Node *tail;//记录队列的尾部
} linkqueue;



#endif
