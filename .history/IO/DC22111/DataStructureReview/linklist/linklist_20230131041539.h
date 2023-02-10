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

//申请节点封装数据

//判空

//头插

//遍历

//按位置查找返回节点

//尾插

//任意位置插入

//头删

//任意位置删除


#endif