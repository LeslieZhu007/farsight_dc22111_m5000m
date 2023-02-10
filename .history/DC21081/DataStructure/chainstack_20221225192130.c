#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//构造链式栈
typedef int data_t;
typedef struct node
{
    data_t data;
    struct node *next;
} chainstack;

//创建空栈
chainstack* chainstack_create()
{
    chainstack* top = (chainstack *)malloc(sizeof(chainstack));
    if (NULL == top)
    {
        return NULL;
    }
    top->data = -1;
    top->next = NULL;
    return top;
}



//判空
int chainstack_empty(chainstack *top)
{
    if (NULL == top)
    {
        return -1;
    }
    return top->next == NULL;
}

//入栈
int chainstack_push(chainstack *top,data_t data)
{
    if (NULL == top)
    {
        return -1;
    }

    //准备新节点插入
    chainstack* new = (chainstack *)malloc(sizeof(chainstack));
    
}

//出栈

int main(int argc, char const *argv[])
{
    
    



    return 0;
}
