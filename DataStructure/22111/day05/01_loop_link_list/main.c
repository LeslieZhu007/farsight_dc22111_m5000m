#include "looplinklist.h"

int main(int argc, char const *argv[])
{
    LoopLinkList L = list_create();
    if(NULL == L)
    {
        return -1;
    }

    //头插
    list_insert_head(L,1);
    list_insert_head(L,2);
    list_insert_head(L,3);
    list_insert_head(L,4);


    list_show(L);
    

    list_insert_pos(L,1,88);
    list_show(L);

    list_insert_tail(L,99);
    list_show(L);

    list_delete_head(L);
    list_show(L);


    list_delete_tail(L);
    list_show(L);

    //调用去头函数
    LoopLinkList H = list_kill_head(L);
    L = NULL;

    list_display(H);


    //释放
    list_free(H);

    H = NULL;

    return 0;
}
