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
    
}



//判空

//入栈

//出栈

int main(int argc, char const *argv[])
{
    
    



    return 0;
}
