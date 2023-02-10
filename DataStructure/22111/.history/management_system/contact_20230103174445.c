#include "contact.h"

//创建
DoubleLoop list_create()
{
    DoubleLoop L = (DoubleLoop)malloc(sizeof(Node));
    if (NULL == L)
    {
        printf("双向循环链表创建失败\n");
        return NULL;
    }
    //链表长度初始化
    L->len = 0;
    L->next = L;
    L->prior = L;
    printf("双向循环链表创建成功\n");
    return L;
}

//申请节点封装数据
DoubleLoop apply_node(datatype e)
{
    //申请节点封装数据
    DoubleLoop p = (DoubleLoop)malloc(sizeof(Node));
    if (NULL == p)
    {
        printf("节点申请失败\n");
        return -2;
    }
    p->data = e;
    p->next = NULL;
    p->prior = NULL;
}

//添加数据==>头插
int list_insert_head(DoubleLoop L,datatype e)
{
    if (NULL == L)
    {
        printf("所给链表不合法\n");
        return -1;
    }
    //申请节点
    DoubleLoop p = apply_node(e);
    //采用头插法进行插入
    p->next = L->next;
    L->next->prior = p;
    L->next = p;
    p->prior = L;

    //表长变化
    L->len++;
    printf("%s 双向循环链表头插成功\n",e.name);
}


void list_show(DoubleLoop L)
{
    
}