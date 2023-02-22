#include "udpchat.h"



linklist list_create()
{
    linklist L = (linklist)malloc(sizeof(Node));
    if (NULL == L)
    {
        ERR_MSG("malloc");
        return NULL;
    }
    L->next = NULL;
}


int list_insert_tail(linklist L,struct sockddr_in e)
{
    if (NULL == L)
    {
        /* code */
    }
    
    return 0;
}