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
int dlinklist_len(dlinklist * head)
{
    if (NULL==head || dlinklist_empty(head) )
    {
        printf("获取长度失败\n");
        return -1;
    }

    int len = 0;
    dlinklist *p = head->next;
    while (p!=NULL)
    {
        len++;
        p=p->next;
    }
    
    return len;
}

//判空
int dlinklist_empty(dlinklist * head)
{
    if (NULL==head)
    {
        return -1;
    }
    
    return head->next == NULL;
}

//增
int dlinklist_insert_pos(dlinklist *head,int pos,data_t data)
{
    if (NULL==head)
    {
        return -1;
    }

    int len = dlinklist_len(head);
    if (pos < 0||pos > len)
    {
        return -1;
    }
    

    //准备新节点
    dlinklist *new = (dlinklist *)malloc(sizeof(dlinklist));
    new->data = data;
    new->next = NULL;
    new->prior= NULL;

    //准备指针p 遍历
    dlinklist *p = head;
    //遍历到pos-1
    while (pos--)
    {
        p=p->next;
    }
    

    //插入新节点
    if (p->next!=NULL)  //中间插入
    {
        new->next=p->next;
        new->prior=p;

        
        p->next = new;
    }
    else
    {
        p->next = new;
        new->prior = p;
        
    }
    
}

//删


//改


//查

//打印

//销毁



int main(int argc, char const *argv[])
{
    
    

    return 0;
}
