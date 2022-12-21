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