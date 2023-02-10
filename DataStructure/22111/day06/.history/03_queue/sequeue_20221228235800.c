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
    return q;
}
//判空
int queue_empty(sequeue *q)
{
    
}
//判满
int queue_full(sequeue *q)
{
    
}
//入队
void queue_push(sequeue *q,datatype e)
{
    
}
//出队
void queue_pop(sequeue *q)
{
    
}
//遍历
void queue_show(sequeue *q)
{
    
}

//队列大小
int queue_size(sequeue *q)
{
    
}

//销毁
void queue_free(sequeue *q)
{
    
}
