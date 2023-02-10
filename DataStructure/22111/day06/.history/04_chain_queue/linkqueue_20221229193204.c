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

    //需要定义一个头节点，让两个指针都指向头节点，表示队列为空
    L->head = (Node *)malloc(sizeof(Node));
    if (NULL == L->head)
    {
        printf("创建失败\n");
        return NULL;
    }

    //给头节点初始化
    L->head->len = 0;
    L->head->next = NULL;

    //将尾指针也指向头节点
    L->tail = L->head;

    printf("链式队列创建成功\n");
    
    return L;
}


//判空
int queue_empty(linkqueue *L)
{
    return L->head == L->tail;
}

//入队
void queue_push(linkqueue *L,datatype e)
{
    //判断逻辑
    if (NULL == L || NULL==L->head) //队列合法，链表合法
    {
        printf("插入失败\n");
        return;
    }
    

    //申请节点封装数据
    Node *p = (Node *)malloc(sizeof(Node));
    if (NULL == p)
    {
        printf("节点申请失败\n");
        return;
    }
    p->data = e;
    p->next = NULL;


    //入队逻辑
    L->tail->next=p; //将新节点放在队尾位置

    L->tail = p; //更新尾指针

    //队长变化
    L->head->len++;

    printf("入队成功\n");
}

//遍历
void queue_show(linkqueue *L)
{
    //判断逻辑
    if (NULL == L ||NULL== L->head || queue_empty(L))
    {
        printf("遍历失败\n");
        return;
    }
    printf("从队头到队尾元素分别是: ");
    //遍历逻辑
    Node * q = L->head;
    while ((q=q->next)!=NULL)
    {
        printf("%d\t",q->data);
    }
    
    printf("\n");
}

//出队
void queue_pop(linkqueue *L)
{
    //头删   （入队 尾插）
    //判断逻辑
    if (NULL == L ||NULL== L->head || queue_empty(L))
    {
        printf("出队失败\n");
        return;
    }

    //出队逻辑==>头删
    /*
    while (L->head->next!=NULL)
    {
        Node *q = L->head->next;
        datatype value = q->data;
        L->head->next = q->next;
        printf("%d出队列成功\n",value);
        free(q);
        q=NULL;
        L->head->len--;p
    }
    */
    Node *p = L->head->next;
    datatype value = p->data;
    L->head->next = p->next;
    free(p);
    p = NULL;

    //队列长度变化
    L->head->len--;

    printf("%d出队成功\n",value);
    
}
//求返回队列长度
int queue_size(linkqueue *L)
{  
    if (NULL!=L && NULL!=L->head)
    {
        return L->head->len;
    }
}

//销毁
void queue_free(linkqueue *L)
{
    if (NULL == L)
    {
        printf("释放失败\n");
        return;
    }
    
    //链表不合法
    if (NULL == L->head)
    {
        free(L); //释放队列的空间
        L = NULL;
        return;
    }

    //都合法  先释放节点，再释放链表，再释放队列
    while (!queue_empty(L))
    {
        queue_pop(L); //将所有节点释放
    }

    //释放头节点，链表
    free(L->head);
    L->head = NULL;

    //释放队列的空间
    free(L);
    L = NULL;

    printf("释放成功\n");
    
}