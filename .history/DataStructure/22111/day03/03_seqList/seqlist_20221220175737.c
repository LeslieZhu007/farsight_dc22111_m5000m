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

int list_insert_pos(seqList *L,int pos,datatype e)
{
    //1.表合法，不为满，插入的位置要合法，才能进行插入操作
    //判断逻辑
    if (NULL==L || list_full(L) || pos < 0 || pos > L->len)
    {
        printf("插入失败\n");
        return -1;
    }
    

    //2. 腾空:将要插入位置一直到顺序表最后一个元素为止，全部后移一格
    //        要从最后一个元素开始往后移动，不能从要插入位置往后移动
    //        会造成数据覆盖

    //2. 腾空
    for (int i = L->len-1; i >=pos; i--)
    {
        L->data[i+1] = L->data[i]; //将当前元素后移一格
        
    }

    //将要插入的位置，放到顺序表中腾出的位置里
    L->data[pos] = e;  
    



    //3.插入成功后，表长自增
    L->len++;

    printf("元素%d插入成功\n",e);

    return 0;

}


int list_delete_pos(seqList *L,int pos)
{

    //1. 顺序表合法，不为空，删除的位置合法的情况下能进行删除操作
     //判断逻辑
    if (NULL==L || list_empty(L) || pos < 0 || pos >= L->len)
    {
        printf("删除失败\n");
        return -1;
    }

    //2. 从要删除的位置下一个起到顺序表的最后一个元素为止，整体前移一格
    for (int i = pos+1; i < L->len; i++)
    {
        L->data[i-1] = L->data[i];
    }
    

    //3. 表长变化
    L->len--;

    printf("元素%d删除成功\n",L->data[pos]);

    return 0;
}


//按位置修改
int list_update_pos(seqList *L,int pos,datatype e)
{
    //1.表合法，非空，位置合法的情况下，允许操作  
    //判断逻辑
    if (NULL == L || list_empty(L) || pos < 0 || pos>=L->len)
    {
        printf("修改失败\n");
        return -1;
    }

    //2.更新顺序表的指定位置的值
    //更新数据
    L->data[pos] = e;

    printf("修改成功\n");
    return 0;
}

//按值修改
int list_update_value(seqList *L,datatype old_e,datatype new_e)
{
    //1.表合法，非空的情况下，允许操作  
    //判断逻辑
    if (NULL == L || list_empty(L))
    {
        printf("修改失败\n");
        return -1;
    }

    int flag = 0; //判断是否进行更新

    //2.找到旧值的位置并更新成新值
    for (int i = 0; i < L->len; i++)
    {
        //判断任意一个元素与旧值比较
        if (L->data[i] == old_e)
        {
            //将当前的值更新成新值
            L->data[i] = new_e;

            flag = 1; //说明进行过更新

            //break;  只更新第一个找到的值
        }
    }

    //判断标识是否被更改
    if (flag == 0)
    {
        printf("未找到要更新的值，修改失败\n");
        return -1;
    }
    printf("按值更新成功\n");
    return 0;
}

//按位置查找返回元素
datatype list_search_pos(seqList *L,int pos)
{
    //判断逻辑
    if (NULL == L || list_empty(L) || pos < 0 || pos >=L->len)
    {
        printf("查找失败\n");
        return;
    }

    return L->data[pos]; //将指定位置的值返回
}

//按值查找返回位置
int list_search_value(seqList *L,datatype e)
{

}

//顺序表排序
void list_sort(seqList *L)
{
    
}

//顺序表去重
void list_unique(seqList *L)
{
    
}


//顺序表释放
void list_free(seqList *L)
{
    
}