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
    p->next = L->next; //新节点指针域指向第一个节点（头节点的下一个节点）
    L->next = p;       //头节点指针域指向新节点
  



    //4.表长变化
    L->len++;
    printf("链表头插成功\n");

}

//遍历
void list_show(LinkList L)
{
    if (NULL == L || list_empty(L))
    {
        printf("链表遍历失败\n");
        return;
    }

    //定义遍历指针，从第一个节点出发
    LinkList q = L->next;
    while (q!=NULL)
    {
        printf("%c\t",q->data);
        q=q->next;
    }
    printf("\n");
}

/*
工具函数
    按位置进行查找函数，返回找到的节点
*/
LinkList find_node(LinkList L,int pos)
{
    //判断逻辑
    if (NULL==L || list_empty(L) || pos < 0 || pos > L->len)
    {
        printf("查找失败\n");
        return NULL;
    }
    //查找逻辑
    LinkList q = L; //定义遍历指针从头节点开始

    for (int i = 1; i <= pos; i++)
    {
        q=q->next;
    }
    
    return q;  //将找到的节点返回
}


//尾插
int list_insert_tail(LinkList L,datatype e)
{
    //1.判断逻辑
    if (NULL==L)
    {
        printf("所给链表不合法\n");
        return -1;
    }

    //2.申请节点,封装数据
    LinkList p = apply_node(e);
    if (NULL == p)
    {
        return -1;
    }

    //找到最后一个节点
    LinkList q = find_node(L,L->len);

    //当作头插 ==> 两个语句相当于一个
    //将q当作头节点进行头插
    p->next = q->next;
    q->next = p;


    //表长变化
    L->len++;

    printf("尾插成功\n");


    return 0;
    
}


//任意位置插入
int list_insert_pos(LinkList L,int pos,datatype e)
{
    //1.判断逻辑
    if (NULL==L || pos < 1 || pos > L->len+1)
    {
        printf("插入失败\n");
        return -1;
    }

    //2.申请节点,封装数据
    LinkList p = apply_node(e);
    if (NULL == p)
    {
        return -1;
    }

    //3.找到要插入节点的前驱节点
    LinkList q = find_node(L,pos-1);

    //4.插入逻辑
    p->next = q->next;
    q->next = p;


    //5.表长变化
    L->len++;

    printf("任意位置插入成功\n");

    return 0;

}


int list_delete_head(LinkList L)
{
    //逻辑判断
    if (NULL==L || list_empty(L))
    {
        printf("头删失败\n");
        return -1;
    }
    
    //删除逻辑
    //1. 标记要删除的节点(第一个节点)
    LinkList p = L->next;

    //2.孤立要删除的节点
    L->next = p->next;  //L->next->next

    //3. 释放要删除的节点
    free(p);

    p = NULL;

    //4.表长自减
    L->len --;

    printf();

    return 0;
}
