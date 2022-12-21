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
    list_add(L,2);

    printf("插入前:\n");
    //调用遍历函数
    list_show(L);

    //调用任意位置插入函数
    printf("当前顺序表中元素有%d个,请输入要插入的位置:\n",L->len);
    int pos,data,delpos;
    scanf("%d",&pos);
    printf("请输入要插入的数据:\n");
    scanf("%d",&data);
    list_insert_pos(L,pos,data);
    printf("插入后:\n");
    list_show(L);

    printf("请输入要删除的位置:\n");
    scanf("%d",&delpos);

    list_delete_pos(L,delpos);
    printf("删除后:\n");
    list_show(L);

    //调用更新函数
    printf("开始更新:\n");
    list_update_pos(L,2,100);
    printf("更新后:\n");
    list_show(L);

    //调用按值更新函数
    printf("开始按值更新:\n");
    list_update_value(L,999,666);
    printf("按值更新后:\n");
    list_show(L);

    //调用排序函数
    list_sort(L);
    list_show(L);

    //调用去重函数
    printf("调用去重函数\n");
    list_unique(L);
    list_show(L);


    //调用销毁函数
    list_free(L); //==>值传递

    list_show(L);


    return 0;
}
