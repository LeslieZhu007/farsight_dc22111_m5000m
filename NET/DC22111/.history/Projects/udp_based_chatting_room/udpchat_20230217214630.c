#include "udpchat.h"



linklist list_create()
{
    linklist L = (linklist)malloc(sizeof(Node));
    if (NULL == L)
    {
        ERR_MSG("list create failed");
        return NULL;
    }
    L->next = NULL;
}
