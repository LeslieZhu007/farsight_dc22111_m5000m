#ifndef __LINKLIST_H__
#define __LINKLIST_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char datatype;

//定义节点结构体
typedef struct Node
{
    union 
    {
        datatype data; //普通节点数据域
        int len; //头节点数据域
    };
    struct Node *next;  //指向下一个节点的指针
} *LinkList,Node;

//创建链表
LinkList list_create();

//判空
int list_empty(LinkList L);

//头插
int list_insert_head(LinkList L,datatype e);

//遍历
void list_show(LinkList L);

//尾插
int list_insert_tail(LinkList L,datatype e);

//任意位置插入
int list_insert_pos(LinkList L,int pos,datatype e);

//头删
int list_delete_head(LinkList L);

//尾删
int list_delete_tail(LinkList L);

//任意删
int list_delete_pos(LinkList L,int pos);

//任意位置修改函数
int list_update_pos(LinkList L,int pos,datatype e);

//按值查找返回对应的位置
int list_search_value(LinkList L,datatype e);

//按值进行修改函数
int list_update_value(LinkList L,datatype old_e,datatype new_e);

//使用选择排序完成单链表的升序排序
void list_sort(LinkList L);

//链表翻转
void list_reverse(LinkList L);

//链表释放
void list_free(LinkList L);

//单向链表简单选择排序
void list_sort(LinkList L);

//链表翻转
LinkList list_recursive_reverse(LinkList L);

#endif
