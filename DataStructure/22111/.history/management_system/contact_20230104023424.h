#ifndef __CONTACT_H__
#define __CONTACT_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//定义人员类型结构体
typedef struct Person
{
    int id;
    char name[20];
    char sex;
    char tel[20];
} datatype;
//定义节点结构体类型
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

//链表初始化
void list_init(DoubleLoop L);

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

//按姓名进行删除
int list_delete_name(DoubleLoop L,char* name);

//按位置及给定信息插入
int list_insert_pos(DoubleLoop L,int pos,datatype e);

//将链表信息导入到文件中
int export_info_to_file(DoubleLoop L);

//按照姓名将通讯录排序
void list_sort_name(DoubleLoop L);


//获取链表长度
int getLength(DoubleLoop L);


//统计性别
void calculate_sex(DoubleLoop L);

//元素交换函数
void swap(datatype *a,datatype *b);

#endif