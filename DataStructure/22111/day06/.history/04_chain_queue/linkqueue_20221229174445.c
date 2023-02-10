#include "linkqueue.h"



//创建
linkqueue * queue_create()
{ 
    //给队列申请空间
    linkqueue *L = (linkqueue *)malloc(sizeof(linkqueue));
    if (NULL == L)
    {
        printf("队列创建失败\n");
        return NULL;
    }

    //创建队列成功后 L->head   L->tail是两个野指针
    

}