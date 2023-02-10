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

//创建

//判空

//申请节点封装数据

//头插

//遍历

//任意位置插入


//尾插

//尾删

//删除头节点

//删除头节点遍历





#endif