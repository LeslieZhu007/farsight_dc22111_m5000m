#ifndef __DOUBLELINK_H__
#define __DOUBLELINK_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int datatype;

typedef struct Node
{
    union
    {
        datatype data;
        int len;

    };
    struct Node *prio;
    struct Node *next;
} *DoubleLinkList,Node;

//创建链表
DoubleLinkList list_create();

//头插
int list_insert_head(DoubleLinkList L,datatype e);

//判空
int list_empty(DoubleLinkList L);

//遍历
void list_show(DoubleLinkList L);

//任意位置插入
int list_insert_pos(DoubleLinkList L,int pos,datatype e);


//头删
int list_delete_head(DoubleLinkList L);

//任意位置删除
int list_delete_pos(DoubleLinkList L,int pos);

//释放
void list_free(DoubleLinkList L);



#endif