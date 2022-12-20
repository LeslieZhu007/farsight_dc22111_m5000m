#include "seqlist.h"


//创建顺序表
seqList *list_create()
{
    //在堆区申请一个顺序表的空间
    seqList *L = (seqList *)malloc(sizeof(seqList));
    if (NULL == L)
    {
        printf("顺序表创建失败\n");
        return NULL;
    }
    //初始化顺序表
    
    return L;
}


//判空
int list_empty(seqList *L)
{

}


//判满
int list_full(seqList *L)
{

}


//添加元素   表尾 尾插
int list_add(seqList *L,datatype e)
{

}


//遍历
void list_show(seqList *L)
{

}