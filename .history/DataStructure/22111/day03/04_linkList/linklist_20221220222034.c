#include "linklist.h"



//创建链表
LinkList list_create()
{
    //在堆区申请一个头节点
    LinkList L = (LinkList)malloc(sizeof(Node));
    if (NULL == L)
    {
        printf("链表创建失败\n");
        return NULL;
    }

    //初始化
    L->len = 0;
    L->next = NULL;  //给指针域初始化
    printf("链表创建成功\n");
    return L;
}

/*
    工具函数
*/
//申请节点，封装数据函数
LinkList apply_node(datatype e)
{
    //申请节点空间
    LinkList p = (LinkList)malloc(sizeof(Node));
    if (NULL == p)
    {
        printf("链表节点申请失败\n");
        return NULL;
    }
    //将数据封装到节点中
    p->data = e;
    p->next = NULL;
    return p;
}