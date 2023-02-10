#ifndef __DLOOPLINKLIST_H__
#define __DLOOPLINKLIST_H__
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
    
} *dlooplinklist,Node;


//创建

//头插

//遍历

//头删





#endif