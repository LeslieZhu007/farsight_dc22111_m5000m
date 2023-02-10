#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 6

typedef int data_t;

typedef struct sequeue
{
    data_t data[SIZE];
    int front; //队头元素的下标
    int rear;  //队尾元素的下标
} sequeue;

//创建顺序队列
sequeue* sequeue_create()
{
    sequeue *sq = (sequeue *)malloc(sizeof(sequeue));
    if (NULL == sq)
    {
        return NULL;
    }
    memset(sq->data,0,sizeof(sq->data));
    sq->front = sq->rear = 0;
    return sq;
}


//判空
int sequeue_empty(sequeue *sq)
{
    if (NULL == sq)
    {
        return -1;
    }

    return sq->front == sq->rear;
}

int sequeue_full(sequeue *sq)
{
    if (NULL == sq)
    {
        return -1;
    }
    if (sq->rear > sq->front)
    {
        return sq->rear - sq->front == SIZE - 1;
    }
    if (sq->rear < sq->front)
    {
        return sq->front- sq->rear  == 1;
    }
}

int sequeue_len(sequeue *sq)
{
    if (NULL == sq)
    {
        return -1;
    }
    int num=0;
    int temp = sq->front;
    while (temp!=sq->rear)
    {
        num++;
        temp = (temp+1)%SIZE;
    }
    return num;
}

int sequeue_push(sequeue *sq,data_t data)
{
    if (NULL == sq)
    {
        return -1;
    }
    if(sequeue_full(sq))
    {
         return -1;
    }
    sq->data[sq->rear] = data;
    sq->rear = (sq->rear + 1) % SIZE;
}


int main(int argc, char const *argv[])
{
    
    


    return 0;
}
