#ifndef __DLINKLIST_H__
#define __DLINKLIST_H__
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

    struct Node* front;
    struct Node* rear;
    
} *dlinklist,Node;


//创建
dlinklist list_create();

//头插
int list_head_insert(dlinklist L,datatype e);

//遍历
void list_loop(dlinklist L)

//判空

//任意位置插

//头删


//任意位置删

//释放





#endif