#include "udpchat.h"



linklist list_create()
{
    linklist L = (linklist)malloc(sizeof(Node));
    if (NULL == L)
    {
        ERR_MSG("list create failed");
    }
    
}

struct sockddr_in apply_node(struct sockddr_in e)
{

}