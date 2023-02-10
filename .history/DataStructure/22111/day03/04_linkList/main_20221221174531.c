#include "linklist.h"


int main(int argc, char const *argv[])
{
    //创建
    LinkList L = list_create();
    if (NULL == L)
    {
        return -1;
    }

    //头插
    list_insert_head(L,'Q');
    list_insert_head(L,'W');
    list_insert_head(L,'E');
    list_insert_head(L,'R');

    //遍历
    list_show(L);
    
    //尾插
    list_insert_tail(L,'D');
    list_insert_tail(L,'F');

    //遍历
    list_show(L);

    //任意位置插入
    list_insert_pos(L,3,'X');

    //遍历
    list_show(L);

    //调用头删
    list_delete_head(L);

    //调用头删
    list_delete_head(L);

     //遍历
    list_show(L);
    
    return 0; 
}
