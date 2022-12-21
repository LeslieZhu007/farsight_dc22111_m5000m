#include "linklist.h"


int main(int argc, char const *argv[])
{
    LinkList L = list_create();
    if (NULL == L)
    {
        return -1;
    }

    list_insert_head(L,'Q');
    list_insert_head(L,'W');
    list_insert_head(L,'E');
    list_insert_head(L,'R');

    //遍历
    list_show(L);
    
    
    return 0; 
}
