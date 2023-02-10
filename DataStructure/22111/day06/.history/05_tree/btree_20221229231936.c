#include "btree.h"

//创建
btree* tree_create()
{
    datatype value;
    scanf("%c",&value);
    getchar();

    if (value == '#')
    {
        return NULL;
    }

    btree* B = (btree *)malloc(sizeof(btree));
    B->data = value; //将数据元素放入数据域
    B->left = tree_create(); //递归创建左子树
    B->right = tree_create(); //递归创建右子树

    return B;  //将创建好的树返回
    
}