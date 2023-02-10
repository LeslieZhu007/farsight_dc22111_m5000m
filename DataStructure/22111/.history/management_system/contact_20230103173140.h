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

DoubleLoop list_create();






#endif