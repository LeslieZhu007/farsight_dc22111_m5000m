#include "doublelink.h"



//创建链表
DoubleLinkList list_create()
{
    DoubleLinkList L = (DoubleLinkList)malloc(sizeof(Node));
    if (NULL == L)
    {
        printf("双向链表创建失败\n");
        return NULL;
    }

    //初始化
    L->len = 0;

    L->prio = NULL;

    L->next = NULL;

    printf("双向链表创建成功\n");

    return L;
    
}

//头插
int list_insert_head(DoubleLinkList L,datatype e)
{
    //判断逻辑
    if (NULL == L)
    {
        printf("所给链表不合法\n");
        return -1;
    }
    
    //申请节点封装数据
    DoubleLinkList p = (DoubleLinkList)malloc(sizeof(Node));
    if (NULL == p)
    {
        printf("节点申请失败\n");
        return -1;
    }
    p->data = e;
    p->prio = NULL;
    p->next = NULL;

    //头插
    if (L->next == NULL) //表空
    {
        p->prio = L;
        L->next=p;
    } else
    {
        p->prio = L;
        p->next = L->next;
        L->next->prio = p;
        L->next = p;
    }
    //表长变化
    L->len++;
    printf("双向链表数据插入成功\n");
    return 0;
}


//判空
int list_empty(DoubleLinkList L)
{
    return L->next == NULL; //1 空  0 非空
}


//遍历
void list_show(DoubleLinkList L)
{
    //判断逻辑
    if (NULL == L || list_empty(L))
    {
        printf("遍历失败\n");
        return;
    }

    //定义遍历指针，将所有节点进行遍历
    DoubleLinkList q = L->next;  //从第一个节点出发
    while (q!=NULL)
    {
        printf("%d ",q->data);
        q=q->next;
    }
    printf("\n");
}


//任意位置插入
int list_insert_pos(DoubleLinkList L,int pos,datatype e)
{
    //判断逻辑
    //判断逻辑
    if (NULL == L || pos < 1 || pos > L->len+1)
    {
        printf("所给链表不合法，任意位置插入失败\n");
        return -1;
    }

    //申请节点封装数据
    DoubleLinkList p = (DoubleLinkList)malloc(sizeof(Node));
    if (NULL == p)
    {
        printf("节点申请失败\n");
        return -2;
    }
    p->data = e;
    p->next = NULL;
    p->prio = NULL;

    //定义遍历指针，找到要插入节点的前驱节点
    DoubleLinkList q = L; //从头节点出发
    for (int i = 1; i <=pos-1; i++)
    {
        q=q->next;
    }
    //判断找到的节点是否是最后一个节点
    if (q->next == NULL)
    {
        p->prio = q;
        q->next = p;
    } else
    {
        p->next = q->next;
        p->prio=q;
        q->next->prio = p; 
        q->next=p;
    }
    
    //表长变化
    L->len++;
    printf("双向链表插入成功\n");
    return 0;
    
}


//头删
int list_delete_head(DoubleLinkList L)
{
    if (NULL == L || list_empty(L))
    {
        printf("头删失败\n");
        return -1;
    }
    //标记要删除的节点
    DoubleLinkList p = L->next;

    //判断该节点是否是最后一个节点
    if (p->next == NULL)
    {
        L->next = NULL;
    } else
    {
        L->next = p->next;
        p->next->prio = L;
    }
    
    //释放要删除的节点
    free(p);
    p = NULL;

    //表长变化
    L->len--;

    printf("头删成功\n");
    return 0;
    
}


//任意位置删除
int list_delete_pos(DoubleLinkList L,int pos)
{
    if (NULL == L || list_empty(L)|| pos < 1 || pos > L->len)
    {
        printf("任意位置删除失败\n");
        return -1;
    }
    
    //定义遍历指针，找到要删除的节点
    DoubleLinkList q = L->next; //从第一一个节点出发
    for (int i = 1; i <pos; i++)
    {
        q=q->next;
    }

    //自我孤立
    if (q->next == NULL)
    {
        q->prio->next = NULL;
    } else
    {
        q->prio->next = q->next;
        q->next->prio = q->prio;
    }

    //自我释放
    free(q);
    q = NULL;

    L->len--;
    printf("任意位置删除成功\n");
    return 0;
    
    
}


//释放
void list_free(DoubleLinkList L)
{
    if (NULL == L)
    {
        printf("释放失败\n");
        return;
    }

    //将所有界定啊释放
    while (L->next!=NULL)
    {
        list_delete_head(L);
    }
    
    //释放头节点
    free(L);
    L = NULL;
    printf("释放成功\n");
    
}