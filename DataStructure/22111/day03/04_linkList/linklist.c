#include "linklist.h"



//创建链表
LinkList list_create()
{
    //在堆区申请一个头节点
    LinkList L = (LinkList)malloc(sizeof(Node));
    if (NULL == L)
    {
        printf("链表创建失败\n");
        return NULL;
    }

    //初始化
    L->len = 0;
    L->next = NULL;  //给指针域初始化
    printf("链表创建成功\n");
    return L;
}

/*
    工具函数
*/
//申请节点，封装数据函数
LinkList apply_node(datatype e)
{
    //申请节点空间
    LinkList p = (LinkList)malloc(sizeof(Node));
    if (NULL == p)
    {
        printf("链表节点申请失败\n");
        return NULL;
    }
    //将数据封装到节点中
    p->data = e;
    p->next = NULL;
    return p;
}


//判空
int list_empty(LinkList L)
{
    return L->next == NULL; //1表示空，0表示非空
}

//头插
int list_insert_head(LinkList L,datatype e)
{
    //1.判断逻辑
    if (NULL==L)
    {
        printf("所给链表不合法\n");
        return -1;
    }
    //2.申请节点封装数据
    LinkList p = apply_node(e);
    if (NULL == p)
    {
        return -1;
    }
    
    //3.头插逻辑
    p->next = L->next; //新节点指针域指向第一个节点（头节点的下一个节点）
    L->next = p;       //头节点指针域指向新节点
  



    //4.表长变化
    L->len++;
    printf("链表头插成功\n");

}

//遍历
void list_show(LinkList L)
{
    if (NULL == L || list_empty(L))
    {
        printf("链表遍历失败\n");
        return;
    }

    //定义遍历指针，从第一个节点出发
    LinkList q = L->next;
    while (q!=NULL)
    {
        printf("%c\t",q->data);
        q=q->next;
    }
    printf("\n");
}

/*
工具函数
    按位置进行查找函数，返回找到的节点
*/
LinkList find_node(LinkList L,int pos)
{
    //判断逻辑
    if (NULL==L || list_empty(L) || pos < 0 || pos > L->len)
    {
        printf("查找失败\n");
        return NULL;
    }
    //查找逻辑
    LinkList q = L; //定义遍历指针从头节点开始

    for (int i = 1; i <= pos; i++)
    {
        q=q->next;
    }
    
    return q;  //将找到的节点返回
}


//尾插
int list_insert_tail(LinkList L,datatype e)
{
    //1.判断逻辑
    if (NULL==L)
    {
        printf("所给链表不合法\n");
        return -1;
    }

    //2.申请节点,封装数据
    LinkList p = apply_node(e);
    if (NULL == p)
    {
        return -1;
    }

    //找到最后一个节点
    LinkList q = find_node(L,L->len);

    //当作头插 ==> 两个语句相当于一个
    //将q当作头节点进行头插
    p->next = q->next;
    q->next = p;


    //表长变化
    L->len++;

    printf("尾插成功\n");


    return 0;
    
}


//任意位置插入
int list_insert_pos(LinkList L,int pos,datatype e)
{
    //1.判断逻辑
    if (NULL==L || pos < 1 || pos > L->len+1)
    {
        printf("插入失败\n");
        return -1;
    }

    //2.申请节点,封装数据
    LinkList p = apply_node(e);
    if (NULL == p)
    {
        return -1;
    }

    //3.找到要插入节点的前驱节点
    LinkList q = find_node(L,pos-1);

    //4.插入逻辑
    p->next = q->next;
    q->next = p;


    //5.表长变化
    L->len++;

    printf("任意位置插入成功\n");

    return 0;

}


int list_delete_head(LinkList L)
{
    //逻辑判断
    if (NULL==L || list_empty(L))
    {
        printf("头删失败\n");
        return -1;
    }
    
    //删除逻辑
    //1. 标记要删除的节点(第一个节点)
    LinkList p = L->next;

    //2.孤立要删除的节点
    L->next = p->next;  //L->next->next

    //3. 释放要删除的节点
    free(p);

    p = NULL;

    //4.表长自减
    L->len --;

    printf("头删成功\n");

    return 0;
}


//任意删
int list_delete_pos(LinkList L,int pos)
{
    //表判断逻辑
    if (NULL == L || list_empty(L) || pos<1 || pos > L->len)
    {
        printf("删除失败\n");
        return -1;
    }
    //找到要删除节点的前驱节点
    LinkList q = find_node(L,pos-1);
    //删除逻辑
    LinkList p = q->next; //标记要删除的节点
    q->next = p->next; //孤立要删除的节点
    free(p);
    p=NULL;

    //表长变化
    L->len--;
    printf("删除成功\n");
    return 0;
}


//尾删
int list_delete_tail(LinkList L)
{
    //表判断逻辑
    if (NULL == L || list_empty(L))
    {
        printf("删除失败\n");
        return -1;
    }
    //找到到数第二个节点
    LinkList q = find_node(L,L->len-1);
    //删除逻辑
    LinkList p = q->next; //标记要删除的节点
    q->next = p->next; //孤立要删除的节点
    free(p);
    p=NULL;

    /*
        方法2:
        free(q->next);  //释放最后一个节点
        q->next = NULL; //将新的最后一个节点的指针域置空
    */

    //表长变化
    L->len--;
    printf("尾删删除成功\n");
    return 0;
}


//任意位置修改函数
int list_update_pos(LinkList L,int pos,datatype e)
{
    //判断逻辑
    if (NULL == L || list_empty(L) || pos < 1 || pos > L->len)
    {
        printf("修改失败\n");
        return -1;
    }

    /*
    //找到要修改的节点
    LinkList p = find_node(L,pos);
    //修改逻辑
    p->data = e;
    */
    find_node(L,pos)->data = e;

    printf("按位置修改成功\n");
    
    return 0;
}

//按值查找返回对应的位置
int list_search_value(LinkList L,datatype e)
{
    //判断逻辑
    if (NULL == L || list_empty(L))
    {
        printf("查找失败\n");
        return -1;
    }
    
    //定义遍历指针从第一个节点出发
    LinkList q = L->next;
    int index = 1;
    while (q!=NULL&&q->data!=e)
    {
        q=q->next;
        index++;
    }
    
    if (index > L->len)
    {
        return -1;
    }
    
    return index; //将找到的节点位置返回
}

//链表翻转
void list_reverse(LinkList L)
{
    //判断逻辑
    if (NULL == L || L->len < 1)
    {
        printf("翻转失败\n");
        return;
    }

    //翻转逻辑
    LinkList H = L->next; //托管链表

    L->next = NULL; //白手起家

    while (H!=NULL) //旧链表不空
    {
        //定义搬运节点
        LinkList p = H; //标记要跳槽的节点
        H = H->next;

        //头插形式插入到新链表中
        p->next = L->next;
        L->next = p;
    }
    
    printf("翻转成功\n");
    
}


//链表释放
void list_free(LinkList L)
{
    //判断逻辑
    if (NULL == L)
    {
        printf("释放失败\n");
        return;
    }

    //将所有的节点进行释放
    while (L->next != NULL)
    {
        list_delete_head(L);
    }

    //将头节点释放
    free(L);
    L=NULL;

    printf("释放成功\n");

}


//按值进行修改函数
int list_update_value(LinkList L,datatype old_e,datatype new_e)
{
    //判断逻辑
    if (NULL == L || list_empty(L))
    {
        printf("修改失败\n");
        return -1;
    }
    

    //通过旧值找到要修改的元素位置
    int pos = list_search_value(L,old_e);
    if(pos<1)
    {
        printf("无旧值，修改失败\n");
        return -2;
    }

    //通过位置修改
    list_update_pos(L,pos,new_e);

    printf("按值修改成功\n");
    return 0;
}


//单向链表简单选择排序
void list_sort(LinkList L)
{
    LinkList p,q; //遍历指针
    LinkList min; //记录最小节点的指针
    for (p =L->next; p->next!=NULL;p=p->next) //外层循环控制已排好序的序列
    {
        min = p; //将第一个当作最值
        for (q = p->next; q != NULL;q=q->next) //遍历待排序序列，找到最小节点
        {
            if(min->data > q->data)
            {
                min = q; //更新最值
            }
        }
        //比较最值是否是待排序的第一个节点，如果不是，则交换数据域
        if (min!=p)
        {
            datatype temp = p->data;
            p->data = min->data;
            min->data = temp;
        }
        
        
    }

    printf("选择排序成功\n");
    
}


//链表翻转
LinkList list_recursive_reverse(LinkList H)
{
    //递归出口
    if (NULL == H || H->next == NULL)
    {
        return H;
    } else
    {
        LinkList new_H = list_recursive_reverse(H->next);//不断递归找新头节点
        H->next->next = H; //将当前节点的后继节点指针域指向自己
        H->next = NULL;  //将自身指针域置空
        return new_H;  //不断向前传递新节点
    }
    
}