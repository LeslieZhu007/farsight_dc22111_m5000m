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
    //1.顺序表合法且不为空的情况下进行遍历
    //判断逻辑
    if (NULL == L || list_empty(L))
    {
        printf("遍历失败\n");
        return;
    }

    //2.本质是对数组的遍历，只遍历数组的前len个元素
    //遍历逻辑
    printf("当前顺序表中的元素分别是: ");
    for (int i = 0; i < L->len; i++)
    {
        printf("%d\t",L->data[i]);
    }
    
    printf("\n");

    
}

void list_insert(seqList *L,int pos,datatype e)
{
    //1.表合法，不为满，插入的位置要合法，才能进行插入操作


    //2. 腾空:将要插入位置一直到顺序表最后一个元素为止，全部后移一格
    //        要从最后一个元素开始往后移动，不能从要插入位置往后移动
    //        会造成数据覆盖



    //3.插入成功后，表长自增
    
}