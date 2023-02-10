#ifndef __LOOPLINKLIST_H__
#define __LOOPLINKLIST_H__
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
    
} *looplinklist,Node;

//创建
looplinklist list_create();
//判空
int list_empty(looplinklist L);

//申请节点封装数据
looplinklist apply_node(datatype e);

//头插
int list_head_insert(looplinklist L,datatype e);

//遍历
void list_loop(looplinklist L);

//任意位置插入
int list_insert_pos(looplinklist L,datatype e,int pos);

//尾插
int list_tail_insert(looplinklist L,datatype e);

//尾删
int list_tail_delete(looplinklist L);

//删除头节点
int list_head_node_delete(looplinklist L);

//删除头节点遍历
int list_loop_without_head(looplinklist L);

//删除头节点后释放
int list_destroy_without_head(looplinklist L);




#endif