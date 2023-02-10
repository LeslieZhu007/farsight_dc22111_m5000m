#ifndef __LINKSTACK_H__
#define __LINKSTACK_H__
#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct Node
{
    union 
    {
        datatype data;
        int len;
    };
    struct Node* next;
} *linkstack,Node;

//创建
linkstack stack_create();

//判空
int stack_empty(linkstack s);

//入栈
void stack_push(linkstack s,datatype e);

//遍历
void stack_show(linkstack s);

//出栈
void stack_pop(linkstack s);

//销毁
void stack_free(linkstack s);


#endif