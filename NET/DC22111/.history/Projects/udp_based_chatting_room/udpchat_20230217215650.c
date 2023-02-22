#include "udpchat.h"



linklist list_create()
{
    linklist L = (linklist)malloc(sizeof(Node));
    if (NULL == L)
    {
        ERR_MSG("malloc");
        return NULL;
    }
    memset(&(L->cin),0,sizeof(L->cin));
    L->next = NULL;
    return L;
}


int list_insert_tail(linklist L,struct sockaddr_in e)
{
    if (NULL == L)
    {
        ERR_MSG("insert fail");
        return NULL;
    }
    
    
    return 0;
}