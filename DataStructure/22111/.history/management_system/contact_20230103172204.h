#ifndef __CONTACT_H__
#define __CONTACT_H__

typedef struct Person
{
    int id;
    char name[20];
    char sex;
    char tel[20];
} Person;

typedef struct Node
{
    union
    {
        Person data;
        int len;
    };
    struct Node *prior;
    struct Node *next;
} *DoubleLoop,Node;








#endif