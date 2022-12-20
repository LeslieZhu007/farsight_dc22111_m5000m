#include "seqlist.h"




int main(int argc, char const *argv[])
{
    seqList *L = list_create();
    if (NULL == L)
    {
        return -1;
    }

    //调用添加函数
    list_add(L,3);
    list_add(L,8);
    list_add(L,2);
    list_add(L,4);

    
    
    return 0;
}
