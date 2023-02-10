#include "seqstack.h"

//创建
seqstack * stack_create()
{
    seqstack *s = (seqstack *)malloc(sizeof(seqstack));
    if(NULL == s)
    {
        printf("创建失败\n");
        return NULL;
    }

    s->top = -1;
    printf("顺序栈创建成功\n");
    return s;
}

//判空
int stack_empty(seqstack *s)
{
    return s->top == -1;
}

//判满
int stack_full(seqstack *s)
{
    return s->top == MAX-1; //1表示满，0表示不满
}
//入栈 压栈 进栈
void stack_push(seqstack *s,datatype e)
{
    if (NULL == s || stack_full(s))
    {
        printf("入栈失败\n");
        return;
    }

    //入栈逻辑: 先加后压
    s->top++;
    s->data[s->top] = e; //将元素压入栈中
    printf("%d入栈成功,top=%d\n",e,s->top);
}

//遍历
void stack_show(seqstack *s){
    if (NULL == s || stack_empty(s))
    {
        printf("遍历失败\n");
        return;
    }

    printf("从栈顶到栈底的元素分别是: ");
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d\t",s->data[i]);
    }
    printf("\n");
}
//出栈 弹栈
void stack_pop(seqstack *s)
{
    if (NULL == s || stack_empty(s))
    {
        printf("出栈失败\n");
        return;
    }

    //出栈逻辑  先弹后间
    datatype value = s->data[s->top];

    s->top --;
    printf("%d出栈成功\n",value);
}

//返回栈中元素个数
int stack_size(seqstack *s)
{
    if (NULL == s)
    {
        printf("所给栈不合法\n");
        return -1;
    }
    return s->top+1; //返回栈顶下标+1 
}

//返回栈顶元素指针
datatype* stack_top(seqstack *s)
{
    if (NULL == s || stack_empty(s))
    {
        printf("失败\n");
    }

    //将栈顶元素返回
    return &(s->data[s->top]);
    
}

//销毁栈
void stack_free(seqstack *s)
{
    if (NULL !=s)
    {
        free(s);
        s = NULL;
    }
    
    printf("销毁成功\n");
}