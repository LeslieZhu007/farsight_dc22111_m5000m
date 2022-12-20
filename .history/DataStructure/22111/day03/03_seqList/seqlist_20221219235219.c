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
    /*
        void *memset(void *s, int c, size_t n);
        DESCRIPTION
            The memset() function fills the first n bytes of the memory area pointed to by s
            with the constant byte c.
    */
    memset(L->data,0,sizeof(L->data)); //初始化数组
    L->len=0;                          //初始化数组长度
    printf("顺序表创建成功\n");
    return L;
}


//判空
int list_empty(seqList *L)
{
    /*
    if (L->len == 0)
    {
        return 1;
    } else
    {
        return 0;
    }

    return L->len==0?1:0;
    */
    return L->len == 0; //1表示空,0表示非空
}


//判满
int list_full(seqList *L)
{
    return L->len == MAX;
}


//添加元素   表尾 尾插
int list_add(seqList *L,datatype e)
{
    //1.在顺序表合法且不为满的情况下可以进行添加操作
    //判断逻辑
    if (NULL == L || list_full(L))
    {
        printf("添加失败\n");
        return -1;
    }

    //2.将元素放到数组下标为len所在的位置
    //添加逻辑
    L->data[L->len] = e;

    //3.顺序表长度自增
    //表常变化
    L->len++;
    printf("添加成功\n");

    return 0;

}


//遍历
void list_show(seqList *L)
{
    
    
}