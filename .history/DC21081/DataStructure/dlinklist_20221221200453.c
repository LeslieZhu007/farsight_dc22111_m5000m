#include <stdio.h>
#include <stdlib.h>

//构造双向链表类型
typedef int data_t;

typedef struct dlink
{
    data_t data;
    struct dlink *next,*prior;
} dlinklist;

//创建空双向链表
dlinklist * dlinklist_create()
{
    dlinklist *head = (dlinklist *)malloc(sizeof(dlinklist));
    head->data = -1;
    head->next = NULL;
    head->prior = NULL;
    return head;
}

//求表长
int dlinklist_len(dlinklist * d)
{

}

//判空


//增删改查

//打印

//销毁



int main(int argc, char const *argv[])
{
    
    

    return 0;
}
