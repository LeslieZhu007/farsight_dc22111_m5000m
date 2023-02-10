#include "looplinklist.h"


//创建
LoopLinkList list_create()
{
    LoopLinkList L = (LoopLinkList)malloc(sizeof(Node));
    if(NULL == L)
    {
        printf("创建链表失败\n");
        return NULL;
    }

    //初始化
    L->len = 0;
    L->next = L; //指针域指向自己， 循环链表中没有一个指针为空

    printf("单向循环链表创建成功\n");

    return L;
}

//判空
int list_empty(LoopLinkList L)
{
    return L->next == L;
}

//申请节点封装数据
LoopLinkList apply_node(datatype e)
{
    LoopLinkList p = (LoopLinkList)malloc(sizeof(Node));
    if(NULL == p)
    {
        printf("节点申请失败\n");
        return NULL;
    }
    //将数据封装到节点中
    p->data = e;
    p->next = NULL;
    return p;
}

//头插法
int list_insert_head(LoopLinkList L,datatype e)
{
    if(NULL == L)
    {
        printf("所给链表不合法\n");
        return -1;
    }
    
    LoopLinkList p = apply_node(e);
    if(NULL ==p)
    {
        return -2;
    }
    
    p->next = L->next;
    L->next = p;
    
    //表长变化
    L->len ++;
    
    printf("插入成功\n");
    
    return 0;
       
}



//遍历
void list_show(LoopLinkList L)
{
    //判断逻辑
    if (NULL == L || list_empty(L))
    {
        printf("遍历失败\n");
        return;
    }

    LoopLinkList q = L->next;
    while(q!=L)
    {
        printf("%d\t",q->data);
        q=q->next;
    }

    printf("\n");
    
}



//按位置查找返回节点
LoopLinkList list_search_pos(LoopLinkList L,int pos)
{
    //判断逻辑
    if (NULL == L || list_empty(L) || pos < 0 || pos > L->len)
    {
        printf("查找失败\n");
        return NULL;
    }
    
    //定义遍历指针进行查找
    LoopLinkList q = L->next;  //从第一个节点出发

    for(int i = 0;i<pos;i++)
    {
        q = q->next;
    }
    
    //将找到的节点返回
    return q;
}


//任意位置插入
int list_insert_pos(LoopLinkList L,int pos,datatype e)
{
    if (NULL == L || pos < 1 || pos > L->len+1)
    {
        printf("任意位置插入失败\n");
        return -1;
    }

    //申请节点封装数据
    LoopLinkList p = apply_node(e);

    //找到要插入位置的前驱节点
    LoopLinkList q = list_search_pos(L,pos-1);

    //插入逻辑
    p->next = q->next;
    q->next = p;

    //表长变化
    L->len++;
    printf("插入成功\n");

    return 0;
    
}


//尾插
int list_insert_tail(LoopLinkList L,datatype e)
{
    if (NULL == L)
    {
        printf("尾插失败\n");
        return -1;
    }
    
    //找到最后一个节点
   // LoopLinkList q = list_search_pos(L,L->len-1);
    
    LoopLinkList q = L->next;
    while (q->next!=L)
    {
        q = q->next;
    }
    

    //申请节点封装数据
    LoopLinkList p = apply_node(e);

    //尾插逻辑
    p->next = L;
    q->next = p;

    //表长变化
    L->len++;

    printf("尾插成功\n");
    return 0;
}


//头删
int list_delete_head(LoopLinkList L)
{
    if(NULL == L || list_empty(L))
    {
        printf("删除失败\n");
        return -1;
    }

    //删除逻辑

    //标记
    LoopLinkList p = L->next;
    //孤立
    L->next = p->next;

    //是否
    free(p);
    p=NULL;

    //表长变化
    L->len--;
    printf("头删除成功\n");
    return 0;
}

//尾删
int list_delete_tail(LoopLinkList L)
{
    if (NULL == L || list_empty(L))
    {
        printf("删除失败\n");
        return -1;
    }
    
    //找到倒数第二个节点
    LoopLinkList q = L;
    while (q->next->next!=L)
    {
        q = q->next;
    }
    

    //删除逻辑
    free(q->next);
    q->next=L;
    /*
    //标记
    LoopLinkList p = q->next;
    //孤立
    q->next = L;   //q->next = p->next
    //释放
    free(p);
    p=NULL;
*/
    //表长变化
    L->len--;
    printf("删除成功\n");
    return 0;
}


//去除头节点
LoopLinkList list_kill_head(LoopLinkList L)
{
    if(NULL == L)
    {
        return NULL;
    }

    if (list_empty(L))
    {
        free(L);
        return NULL;
    }
    

    //找到最后一个节点
    LoopLinkList q = L;
    while (q->next!=L)
    {
        q = q->next;
    }

    //删除头节点操作
    q->next = L->next;  //孤立头节点

    free(L);  //释放头节点

    printf("去头成功\n");

    return q->next; //将第一个节点返回


    
}

//去除头节点的遍历
void list_display(LoopLinkList H)
{
    //判断逻辑
    if (NULL == H)
    {
        printf("遍历失败\n");
        return;
    }

    //遍历逻辑
    LoopLinkList q = H;  //从第一个节点出发
    do
    {
        printf("%d\t",q->data);
        q = q->next;
    } while (q!=H);

    printf("\n");
    
    
}


//释放
void list_free(LoopLinkList H)
{
    if(NULL == H)
    {
        printf("释放失败\n");
        return;
    }

    //将所有节点进行释放
    while (H->next!=H)
    {
        LoopLinkList p = H->next; //标记
        H->next = p->next;
        printf("%d被释放\n",p->data);
        free(p); //释放
        p = NULL;
    }
    
    //将第一个节点释放
    free(H);
    H = NULL;
    printf("链表释放成功\n");
}