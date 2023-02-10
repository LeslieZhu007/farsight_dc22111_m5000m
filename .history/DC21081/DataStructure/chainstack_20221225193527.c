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
    new->data = data;
    new->next = top->next;
    top->next = new;
    return 0;
}

//出栈
int chainstack_pop(chainstack *top)
{
    if (NULL == top)
    {
        return -1;
    }

    if (chainstack_empty(top))
    {
        return -1;
    }

    data_t val = top->next->data;

    chainstack *q = top->next; //备份

    top->next = q->next;

    free(q);
    q = NULL;
    return val;
}

int main(int argc, char const *argv[])
{
    chainstack *top = chainstack_create();
    if (NULL == top)
    {
        return -1;
    }
    
    chainstack_push(top,1);
    chainstack_push(top,2);
    chainstack_push(top,3);
    chainstack_push(top,4);
    chainstack_push(top,5);

    printf("%d\n",chainstack_pop(top));
    printf("%d\n",chainstack_pop(top));
    printf("%d\n",chainstack_pop(top));
    printf("%d\n",chainstack_pop(top));
    printf("%d\n",chainstack_pop(top));



    return 0;
}
