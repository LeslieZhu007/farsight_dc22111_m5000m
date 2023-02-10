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




#endif