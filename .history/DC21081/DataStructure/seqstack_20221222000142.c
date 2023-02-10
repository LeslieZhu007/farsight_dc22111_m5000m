#include <stdio.h>
#include <stdlib.h>
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
