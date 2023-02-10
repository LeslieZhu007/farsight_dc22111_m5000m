#include "seqstack.h"



int main(int argc, char const *argv[])
{
    
    seqstack *s = stack_create();
    if(NULL == s)
    {
        return -1;
    }

    stack_push(s,3);
    stack_push(s,8);
    stack_push(s,7);
    stack_push(s,2);
    stack_push(s,4);

    stack_show(s);

    //调用出栈函数
    stack_pop(s);
    stack_pop(s);
    stack_pop(s);
    // stack_pop(s);
    // stack_pop(s);

    //输出栈顶元素
    printf("目前栈顶元素为:%d\n",*stack_top(s));
    *stack_top(s) = 520;
    printf("目前栈顶元素为:%d\n",*stack_top(s));
    stack_show(s);

    stack_free(s);
    s = NULL;
    return 0;
}
