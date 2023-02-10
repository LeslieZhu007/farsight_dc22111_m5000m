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

//尾插
int list_insert_tail(DoubleLoop L,datatype e);

//展示所有信息
void list_show(DoubleLoop L);

//按名字查找信息
int list_find_name(DoubleLoop L,char* name);

//按参数查找信息
int list_find_data(DoubleLoop L,datatype data);




//修改联系人信息
int list_update_contacts(DoubleLoop L,datatype e);






#endif