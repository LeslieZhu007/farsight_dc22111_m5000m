#include "linkqueue.h"



//创建
linkqueue * queue_create()
{ 
    //给队列申请空间
    linkqueue *L = (linkqueue *)malloc(sizeof(linkqueue));
    if (NULL == L)
    {
        printf("队列创建失败\n");
        return NULL;
    }

    //创建队列成功后 L->head   L->tail是两个野指针

    //需要定义一个头节点，让两个指针都指向头节点，表示队列为空
    L->head = (Node *)malloc(sizeof(Node));
    if (NULL == L->head)
    {
        printf("创建失败\n");
        return NULL;
    }

    //给头节点初始化
    L->head->len = 0;
    L->head->next = NULL;

    //将尾指针也指向头节点
    L->tail = L->head;

    printf("链式队列创建成功\n");
    
    return L;
}


//判空
int queue_empty(linkqueue *L)
{

}

//入队
void queue_push(linkqueue *L,datatype e)
{
    
}

//遍历
void queue_show(linkqueue *L)
{

}

//出队
void queue_pop(linkqueue *L)
{

}
//求返回队列长度
int queue_size(linkqueue *L)
{

}

//销毁
void queue_free(linkqueue *L)
{
    
}