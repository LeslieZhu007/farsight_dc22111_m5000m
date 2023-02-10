#include "linkstack.h"


int main(int argc, char const *argv[])
{
    linkstack s = stack_create();
    if (NULL == s)
    {
        return -1;
    }
    
    stack_push(s,1);
    stack_push(s,2);
    stack_push(s,3);

    stack_show(s);

    return 0;
}
