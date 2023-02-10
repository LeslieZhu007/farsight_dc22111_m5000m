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

//判满

//入栈

//出栈


//打印

//清空

int main(int argc, char const *argv[])
{
    
    




    return 0;
}
