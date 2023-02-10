#ifndef __CONTACT_H__
#define __CONTACT_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person
{
    int id;
    char name[20];
    char sex;
    char tel[20];
} datatype;

typedef struct Node
{
    union
    {
        datatype data;
        int len;
    };
    struct Node *prior;
    struct Node *next;
} *DoubleLoop,Node;

//创建
DoubleLoop list_create();

//申请节点封装数据
DoubleLoop apply_node(datatype e);

//头插
int list_insert_head(DoubleLoop L,datatype e);

//展示所有信息
void list_show(DoubleLoop L);






#endif