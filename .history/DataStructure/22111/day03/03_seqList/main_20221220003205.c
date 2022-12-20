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

    printf("插入前:\n");
    //调用遍历函数
    list_show(L);

    //调用任意位置插入函数
    printf("请输入要插入的位置:\n");
    int pos,data;
    scanf("%d",&pos);
    printf("请输入要插入的数据:\n");
    list_insert_pos(L,1,5);
    printf("插入后:\n");
    list_show(L);
    
    return 0;
}
