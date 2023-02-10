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
    //list_delete_head(L);

    //调用头删
    //list_delete_head(L);

    //调用任意位置删
    //list_delete_pos(L,3);

    //调用尾删
    list_delete_tail(L);

    list_delete_tail(L);

    //按位置修改
    list_update_pos(L,1,'Z');

     //遍历
    list_show(L);

    //调用按值查找返回位置
    int pos = list_search_value(L,'Z');
    if(pos < 0)
    {
        printf("没有找到\n");
    } else
    {
        printf("在%d的位置\n",pos);
    }

    //调用翻转函数
    list_reverse(L);
    list_show(L);

    /*
    list_free(L);
    L = NULL;
    list_show(L);
    */


    list_update_value(L,'Z','W');
    list_show(L);

    list_sort(L);
    list_show(L);


    L->next = list_recursive_reverse(L->next);
    list_show(L);
    return 0; 
}
