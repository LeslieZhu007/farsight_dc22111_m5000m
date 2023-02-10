#ifndef __LOOPLINKLIST_H__
#define __LOOPLINKLIST_H__
#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct Node
{
    union
    {
        datatype data;
        int len;
    };
    struct Node *next;

} *LoopLinkList,Node;

//创建
LoopLinkList list_create();

//判空
int list_empty(LoopLinkList L);

//申请节点封装数据
LoopLinkList apply_node(datatype e);

//按位置查找返回节点
LoopLinkList list_search_pos(LoopLinkList L,int pos);

//头插
int list_insert_head(LoopLinkList L,datatype e);

//遍历
void list_show(LoopLinkList L);

//任意位置插入
int list_insert_pos(LoopLinkList L,int pos,datatype e);


//尾插
int list_insert_tail(LoopLinkList L,datatype e);


//头删
int list_delete_head(LoopLinkList L);

//尾删
int list_delete_tail(LoopLinkList L);

//去除头节点
LoopLinkList list_kill_head(LoopLinkList L);

//去除头节点的遍历
void list_display(LoopLinkList H);


//释放
void list_free(LoopLinkList H);




#endif