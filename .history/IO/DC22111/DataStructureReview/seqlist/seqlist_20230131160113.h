#ifndef __SEQLIST_H__
#define __SEQLIST_H__
#define ERR_MSG(msg) do\
{\
    fprintf(stderr,"line:%d\n",__LINE__);\
    perror(msg);\
} while (0);
#define MAX 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int datatype;

typedef struct 
{
    int len;
    datatype data[MAX];
} seqlist;


//创建
seqlist* list_create();

//判空
int list_empty(seqlist *s);

//判满
int list_full(seqlist *s);

//添加元素
int list_insert(seqlist *s,datatype e);

//遍历
int list_loop(seqlist *s);

//任意位置插入
int list_insert_pos(seqlist *s,datatype e,int pos);

//任意位置删除
int list_delete_pos(seqlist *s,int pos);

//按位置修改
int list_update_pos(seqlist *s,int pos);

//按值修改
int list_update_value(seqlist *s,datatype e);

//按位置查找返回元素
dat

//按值查找返回位置

//顺序表排序

//顺序表去重

//销毁








#endif