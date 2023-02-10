#include "btree.h"



int main(int argc, char const *argv[])
{
    
    //创建
    btree* B = tree_create();
    if (NULL == B)
    {
        return -1;
    } else
    {
        printf("创建成功\n");
    }
    
    //先序遍历
    printf("先序遍历的结果为:");
    tree_show(B);

    printf("\n");

    //中序遍历
    printf("中序遍历的结果为:");
    in_order(B);
    return 0;
}
