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





int main(int argc, char const *argv[])
{
    
    


    return 0;
}
