#include "btree.h"

//创建
btree* tree_create()
{
    btree *b = (btree *)malloc(sizeof(btree));
    if (NULL == b)
    {
        /* code */
    }
    datatype value;
    scanf("%c",&value);
    getchar();

    if (value == '#')
    {
        return NULL;
    }
    
    
}