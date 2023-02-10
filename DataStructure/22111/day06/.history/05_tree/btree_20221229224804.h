#ifndef __BTREE_H__
#define __BTREE_H__
#include <stdio.h>


typedef char32_t datatype;

struct Node
{
    datatype data;     //数据域
    struct Node *left; //指向左子树
    struct Node *right;//指向右子树
};




#endif