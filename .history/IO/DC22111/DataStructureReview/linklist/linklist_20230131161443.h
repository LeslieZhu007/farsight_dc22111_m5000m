#ifndef __LINKLIST_H__
#define __LINKLIST_H__
#define ERR_MSG(msg) do\
{\
    fprintf(stderr,"line:%d\n",__LINE__);\
    perror(msg);\
} while (0);
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int datatype;
typedef struct Node
{
    union
    {
        int len;
        datatype data;
    };
    
    struct Node* next;

} *linklist,Node;

//创建
linklist list_create();

//申请节点封装数据
linklist apply_node(datatype e);

//判空
int list_empty(linklist L);

//头插
int list_head_insert(linklist L,datatype e);

//遍历
void list_loop(linklist L);

//按位置查找返回节点
linklist list_search_pos(linklist L,int pos);

//尾插
int list_tail_insert(linklist L,datatype e);

//任意位置插入
int list_insert_pos(linklist L,datatype e,int pos);

//头删
int list_head_delete(linklist L);

//任意位置删除
int list_delete_pos(linklist L,int pos);

#endif