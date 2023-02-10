#include "linkstack.h"



//创建
linkstack stack_create()
{
    linkstack s = (linkstack)malloc(sizeof(Node));
    if (NULL == s)
    {
        printf("创建链式栈失败\n");
        return NULL;
    }

    //初始化栈
    s->len = 0;
    s->next = NULL;
    
    printf("创建链式栈成功\n");


    return s;
    

}

//判空
int stack_empty(linkstack s)
{
    return s->next == NULL;
}

//入栈 头插
void stack_push(linkstack s,datatype e)
{
    if (NULL == s)
    {
        printf("头插失败\n");
        return;
    }
    
    //申请节点封装数据
    linkstack p = (linkstack)malloc(sizeof(Node));
    if (NULL == p)
    {
        printf("节点申请失败\n");
        return;
    }
    p->data = e;
    p->next = NULL;

    //入栈操作
    p->next = s->next;
    s->next = p;

    //栈的长度变化
    s->len++;

    printf("链式栈入栈成功\n");
    
}

//遍历
void stack_show(linkstack s)
{
    if (NULL == s || stack_empty(s))
    {
        printf("遍历失败\n");
        return;
    }

    //定义遍历指针从第一个节点出发
    linkstack q = s->next;
    printf("从栈顶到栈底元素分别是:");
    while (q!=NULL)
    {
        printf("%d\t",q->data);
        q=q->next;
    }
    printf("\n");
    
    
}

//出栈
void stack_pop(linkstack s)
{
    
}

//销毁
void stack_free(linkstack s)
{
    
}