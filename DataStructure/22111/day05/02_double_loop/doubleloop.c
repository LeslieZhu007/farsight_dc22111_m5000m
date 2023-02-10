
#include "doubleloop.h"


DoubleLoop list_create()
{
    DoubleLoop L = (DoubleLoop)malloc(sizeof(Node));
    if(NULL == L)
    {
        printf("创建失败\n");
        return NULL;
    }
    //初始化
    L->len = 0;
    L->next = L;
    L->prio = L;

    printf("双向循环链表创建成功\n");
    return L;
}

int list_insert_head(DoubleLoop L,datatype e)
{
    if (NULL == L)
    {
        printf("所给链表不合法\n");
        return -1;
    }
    
    //申请节点封装数据
    DoubleLoop p = (DoubleLoop)malloc(sizeof(Node));
    if (NULL == p)
    {
        printf("节点申请失败\n");
        return -2;
    }
    p->data = e;
    p->next = NULL;
    p->prio = NULL;


    //头插逻辑
    p->next = L->next;
    p->prio = L;

    L->next->prio = p;
    L->next = p;

    //表长变化
    L->len++;

    printf("头插成功\n");
    
}

void list_show(DoubleLoop L)
{
    if (NULL == L || L->next == L)
    {
        printf("遍历失败\n");
        return;
    }

    //定义遍历指针，从第一个节点出发
    DoubleLoop q = L->next;
    while (q!= L)
    {
        printf("%d\t",q->data);
        q = q->next;
    }
    
    printf("\n");
    
}

int list_delete_head(DoubleLoop L)
{
    if(NULL == L || L->next == L)
    {
        printf("删除失败\n");
        return -1;
    }
    //头删逻辑
    DoubleLoop p = L->next;
    L->next = p ->next;
    p->next->prio = L;

    free(p);
    p = NULL;

    L->len --;

    printf("删除成功\n");
    return 0;
}