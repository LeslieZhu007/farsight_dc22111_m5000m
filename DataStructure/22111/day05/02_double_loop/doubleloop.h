#ifndef __DOUBLELOOP_H__
#define __DOUBLELOOP_H__

#include <stdio.h>
#include <stdlib.h>

typedef int datatype;


typedef struct Node
{
    union
    {
        datatype data;
        int len;
    };
    struct Node *prio;
    struct Node *next;

} *DoubleLoop,Node;


DoubleLoop list_create();

int list_insert_head(DoubleLoop L,datatype e);

void list_show(DoubleLoop L);

int list_delete_head(DoubleLoop L);




#endif