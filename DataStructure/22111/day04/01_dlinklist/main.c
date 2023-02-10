#include "doublelink.h"





int main(int argc,const char* argv[])
{
    //创建链表
    DoubleLinkList L = list_create();

    //调用头插
    list_insert_head(L,3);
    list_insert_head(L,7);
    list_insert_head(L,2);
    list_insert_head(L,1);

    //调用遍历函数
    list_show(L);

    //调用任意位置插入
    list_insert_pos(L,3,5);
    list_insert_pos(L,5,11);
    list_show(L);

    //头删
    list_delete_head(L);
    list_delete_head(L);

    list_show(L);

    //调用任意位置删除
    list_delete_pos(L,1);
    list_show(L);

    //释放
    list_free(L);
    L=NULL;
    list_show(L);

    return 0;
}