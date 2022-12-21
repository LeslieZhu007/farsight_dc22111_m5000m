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


//判空
int list_empty(LinkList L)
{
    return L->next == NULL; //1表示空，0表示非空
}

//头插
int list_insert_head(LinkList L,datatype e)
{
    //1.判断逻辑
    if (NULL==L)
    {
        printf("所给链表不合法\n");
        return -1;
    }
    //2.申请节点封装数据
    LinkList p = apply_node(e);
    if (NULL == p)
    {
        return -1;
    }
    

    //3.头插逻辑

    //4.表长变化

}