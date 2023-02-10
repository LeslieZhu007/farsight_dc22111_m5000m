#include "doubleloop.h"


int main()
{

    DoubleLoop L = list_create();
    if(NULL  == L)
    {
        return -1;
    }

    list_insert_head(L,1);
    list_insert_head(L,2);
    list_insert_head(L,3);
    list_insert_head(L,4);

    list_show(L);

    list_delete_head(L);
    list_delete_head(L);

    list_show(L);


}