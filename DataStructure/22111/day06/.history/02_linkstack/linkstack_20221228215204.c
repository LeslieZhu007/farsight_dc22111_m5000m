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
    
}

//入栈
void stack_push(linkstack s,datatype e)
{
    
}

//遍历
void stack_show(linkstack s)
{
    
}

//出栈
void stack_pop(linkstack s)
{
    
}

//销毁
void stack_free(linkstack s)
{
    
}