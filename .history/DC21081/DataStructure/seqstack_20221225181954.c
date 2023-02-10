#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 6

//构造顺序栈类型
typedef int data_t;
typedef struct 
{
    data_t data[MAXLEN];
    data_t top; //栈顶
} seqstack;

//创建空栈
seqstack *seqstack_create()
{
    seqstack *s = (seqstack *)malloc(sizeof(seqstack));
    if (NULL==s)
    {
        return  NULL;
    }
    //初始化顺序栈
    memset(s->data,0,MAXLEN);
    s->top = -1;
    return s;
}

//判空
int seqstack_empty(seqstack *s)
{
    if (NULL==s)
    {
        return  -1;
    }

    return s->top == -1;
}


//判满
int seqstack_full(seqstack *s)
{
    if (NULL==s)
    {
        return  -1;
    }
    return s->top + 1 == MAXLEN;
}

//入栈
int seqstack_push(seqstack *s,data_t data)
{
    if (NULL==s)
    {
        return  -1;
    }

    //判满
    if (seqstack_full(s))
    {
        return  -1;
    }
    s->top++; //将栈顶后挪
    s->data[s->top] = data; //将数据放到对应位置
    return 0;
}

//出栈
int seqstack_pop(seqstack *s)
{
    if (NULL==s)
    {
        return  -1;
    }
    //判空
    if (seqstack_empty(s))
    {
        return  -1;
    }
    data_t pop_data = s->data[s->top];
    s->top--;
    return pop_data;
}


//清空
int seqstack_clear(seqstack *s)
{
    if (NULL == s)
    {
        return -1;
    }

    s->top = -1;
    return 0;
}

int main(int argc, char const *argv[])
{
    
    seqstack *s = seqstack_create();
    if (NULL == s)
    {
        return -1;
    }
    
    seqstack_push(s,1);
    seqstack_push(s,2);
    seqstack_push(s,3);

    seqstack_pop(s);
    seqstack_pop(s);
    seqstack_pop(s);

    return 0;
}
