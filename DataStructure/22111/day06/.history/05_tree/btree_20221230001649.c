#include "btree.h"

//创建
btree* tree_create()
{
    datatype value; //数据元素
    scanf("%c",&value);
    getchar();

    //对数据元素进行判断
    if (value == '#')
    {
        return NULL; //递归出口      
    }
    
    //申请节点封装数据
    btree* B = (btree *)malloc(sizeof(btree));
    if (NULL == B)
    {
        printf("节点申请失败\n");
        return NULL;
    }
    
    B->data = value; //将数据元素放入数据域
    B->left = tree_create(); //递归创建左子树
    B->right = tree_create(); //递归创建右子树
    return B;  //将创建好的树返回
}

void tree_show(btree *B)
{
    if (NULL == B)
    {
        return;  //递归出口
    }

    //输出数据域
    printf("%c\t",B->data);

    //先序遍历左子树
    tree_show(B->left);
    //先序遍历右子树
    tree_show(B->right);
    
}