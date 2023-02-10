#ifndef __BTREE_H__
#define __BTREE_H__
#include <stdio.h>
#include <stdlib.h>

typedef char datatype;

typedef struct Node
{
    datatype data;     //数据域
    struct Node *left; //指向左子树
    struct Node *right;//指向右子树
} btree;

//创建
btree* tree_create();

//遍历
void tree_show(btree *B);


#endif