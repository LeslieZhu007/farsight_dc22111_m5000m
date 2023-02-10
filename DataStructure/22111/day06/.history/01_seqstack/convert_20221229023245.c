#include "seqstack.h"

/*
    进制转换: m是要转换的数，n是进制数
*/
void convert_num(seqstack *s,int m,int n)
{
    while (m/n!=0)
    {
        stack_push(s,m%n);
    }
    stack_show(s);
    
}

int main(int argc, char const *argv[])
{
    seqstack *s = stack_create();
    if(NULL == s)
    {
        return -1;
    }
    
    convert_num(s,8,2);



    return 0;
}
