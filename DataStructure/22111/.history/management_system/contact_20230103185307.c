#include "contact.h"

//创建
DoubleLoop list_create()
{
    DoubleLoop L = (DoubleLoop)malloc(sizeof(Node));
    if (NULL == L)
    {
        printf("双向循环链表创建失败\n");
        return NULL;
    }
    //链表长度初始化
    L->len = 0;
    L->next = L;
    L->prior = L;
    printf("双向循环链表创建成功\n");
    return L;
}

//申请节点封装数据
DoubleLoop apply_node(datatype e)
{
    //申请节点封装数据
    DoubleLoop p = (DoubleLoop)malloc(sizeof(Node));
    if (NULL == p)
    {
        printf("节点申请失败\n");
        return NULL;
    }
    p->data = e;
    p->next = NULL;
    p->prior = NULL;
}

//添加数据==> 尾插
int list_insert_tail(DoubleLoop L,datatype e)
{
    if (NULL == L)
    {
        printf("所给链表不合法\n");
        return -1;
    }
    //申请节点
    DoubleLoop p = apply_node(e);

    /*
    //采用头插法进行插入
    p->next = L->next;
    L->next->prior = p;
    L->next = p;
    p->prior = L;
    */
    //采用尾插法
    DoubleLoop q = L->next;
    while (q->next!=L)
    {
        q=q->next;
    }
    p->next = q->next;
    p->prior= q;
    q->next = p;
    L->prior = p;


    //表长变化
    L->len++;
    printf("%s 双向循环链表尾插成功\n",e.name);
}

//展示所有人员信息
void list_show(DoubleLoop L)
{
    if (NULL == L || L->next == L)
    {
        printf("遍历失败\n");
        return;
    }

    //定义遍历指针，从第一个节点出发
    DoubleLoop q = L->next;
    printf("所有人员信息如下:\n");
    printf("编号\t姓名\t性别\t电话\t\t\n");
    while (q!= L)
    {
        printf("%d\t%s\t%c\t%s\t\t\n",q->data.id,q->data.name,q->data.sex,q->data.tel);
        q = q->next;
    }
    printf("\n");
}



int list_find_name(DoubleLoop L,char* name)
{
    if (NULL == L)
    {
        printf("所给链表不合法\n");
        return -1;
    }

    if (strlen(name) == 0)
    {
        printf("所给名字不能为空\n");
        return -2;
    }

    //定义遍历指针，从第一个节点出发
    DoubleLoop q = L->next;
    int flag = 0;
    while (q!= L)
    {
        //进行对比
        if (strcmp(q->data.name,name) == 0)
        {
            printf("%s的信息已找到,详细信息如下\n",name);
            printf("编号\t姓名\t性别\t电话\t\t\n");
            printf("%d\t%s\t%c\t%s\t\t\n",q->data.id,q->data.name,q->data.sex,q->data.tel);
            flag = 1;
            break;
        }
        q = q->next;
    }
    if (flag == 0)
    {
        printf("%s的信息未找到\n",name);
    }
}