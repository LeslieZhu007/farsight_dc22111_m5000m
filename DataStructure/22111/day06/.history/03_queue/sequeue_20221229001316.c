#include "sequeue.h"


//创建
sequeue * queue_create()
{
    sequeue *q = (sequeue *)malloc(sizeof(sequeue));
    if (NULL == q)
    {
        printf("创建队列失败\n");
        return NULL;
    }
    //初始化
    q->front = q->tail = 0;
    printf("顺序栈创建成功\n");
    return q;
}
//判空
int queue_empty(sequeue *q)
{
    return q->front == q->tail;
}
//判满
int queue_full(sequeue *q)
{
    return (q->tail + 1)%MAX == q->front;
}
//入队
void queue_push(sequeue *q,datatype e)
{
    if (NULL == q || queue_full(q))
    {
        printf("入队失败\n");
        return;
    }
    //将数据元素放在队尾所在位置
    q->data[q->tail] = e;

    //队尾后移
    q->tail = (q->tail + 1)%MAX; //重要

    printf("入队成功\n");
    
}
//出队
void queue_pop(sequeue *q)
{

    
    
}
//遍历
void queue_show(sequeue *q)
{
    //从队头到队尾将元素输出

    //判断逻辑

    //遍历逻辑
}

//队列大小
int queue_size(sequeue *q)
{
    
}

//销毁
void queue_free(sequeue *q)
{
    
}
