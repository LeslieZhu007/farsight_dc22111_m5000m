#ifndef __SEQUEUE_H__

#define __SEQUEUE_H__
#define MAX 8

#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct 
{
    datatype data[MAX];
    int front; //对头下标
    int tail;  //队尾
} sequeue;

//创建
sequeue * queue_create();
//判空
int queue_empty(sequeue *q);
//判满
int queue_full(sequeue *q);
//入队
void queue_push(sequeue *q,datatype e);
//出队
void queue_pop(sequeue *q);
//遍历
void queue_show(sequeue *q);
//队列大小
int queue_size(sequeue *q);
//销毁
void queue_free(sequeue *q);

#endif