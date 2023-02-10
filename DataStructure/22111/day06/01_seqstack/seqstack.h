#ifndef __SEQSTACK_H__
#define __SEQSTACK_H__
#include <stdio.h>
#include <stdlib.h>

#define MAX 20
typedef int datatype;

typedef struct 
{
    datatype data[MAX]; //存储栈的数组
    int top; //记录栈顶元素所在下标
} seqstack;

//创建
seqstack * stack_create();

//判空
int stack_empty(seqstack *s);

//判满
int stack_full(seqstack *s);

//入栈 压栈 进栈
void stack_push(seqstack *s,datatype e);

//遍历
void stack_show(seqstack *s);
//出栈 弹栈
void stack_pop(seqstack *s);

//返回栈中元素个数
int stack_size(seqstack *s);

//返回栈顶元素指针
datatype* stack_top(seqstack *s);

//销毁栈
void stack_free(seqstack *s);











#endif