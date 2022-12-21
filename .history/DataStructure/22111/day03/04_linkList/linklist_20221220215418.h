#ifndef __LINKLIST_H__
#define __LINKLIST_H__

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
} *LinkList,Node




#endif