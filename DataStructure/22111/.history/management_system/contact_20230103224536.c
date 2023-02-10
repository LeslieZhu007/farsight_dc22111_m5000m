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
    list_init(L);
    printf("双向循环链表创建成功\n");
    return L;
}

//链表初始化
void list_init(DoubleLoop L)
{
    //链表长度初始化
    L->len = 0;
    L->next = L;
    L->prior = L;
    printf("链表初始化成功\n");
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


//根据姓名查找信息
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
            return flag;
        }
        q = q->next;
    }
    if (flag == 0)
    {
        printf("%s的信息未找到\n",name);
        return flag;
    }
}


//按参数查找信息
int list_find_data(DoubleLoop L,datatype data)
{
    if (NULL == L)
    {
        printf("所给链表不合法\n");
        return -1;
    }

    //定义遍历指针，从第一个节点出发
    DoubleLoop q = L->next;
    int flag = 0;
    while (q!= L)
    {
        //进行对比
        if (strcmp(q->data.name,data.name) == 0)
        {
            printf("姓名为%s的信息已找到\n",data.name);
            flag = 1;
            return flag;
        }

        if (q->data.id == data.id)
        {
            printf("id%d的信息已找到\n",data.id);
            flag = 1;
            return flag;
        }

        if (strcmp(q->data.tel,data.tel) == 0)
        {
            printf("电话为%s的信息已找到\n",data.tel);
            flag = 1;
            return flag;
        }
        q = q->next;
    }
    if (flag == 0)
    {
        if (strcmp(q->data.name,data.name) == 0)
        {
            printf("%s的信息未找到\n",data.name);
        }

        if (q->data.id == data.id)
        {
            printf("id%d的信息未找到\n",data.id);
        }
        if (strcmp(q->data.tel,data.tel) == 0)
        {
            printf("电话为%s的信息未找到\n",data.tel);
        }
        return flag;
    }

}


//修改联系人信息
int list_update_contacts(DoubleLoop L,datatype e)
{
    if (NULL == L)
    {
        printf("所给链表不合法\n");
        return -1;
    }
    int result = list_find_data(L,e);
    if (result <=0)
    {
        printf("要修改的信息查找失败,无法进行修改\n");
        return result;
    }

    DoubleLoop q = L->next;
    while (q!= L)
    {
        //进行对比
        if (strcmp(q->data.name,e.name) == 0)
        {
            printf("对姓名为%s的信息进行修改\n",e.name);
            strcpy(q->data.name,e.name);
            q->data.id = e.id;
            q->data.sex = e.sex;
            strcpy(q->data.tel,e.tel);
            printf("对姓名为%s的信息进行修改成功\n",e.name);
            return 1;
        }

        if (q->data.id = e.id)
        {
            printf("对id为%d的信息进行修改成功\n",e.id);
            strcpy(q->data.name,e.name);
            q->data.id = e.id;
            q->data.sex = e.sex;
            strcpy(q->data.tel,e.tel);
            return 1;
        }

        if (strcmp(q->data.tel,e.tel) == 0)
        {
            printf("对电话为%s的信息进行修改成功\n",e.tel);
            strcpy(q->data.name,e.name);
            q->data.id = e.id;
            q->data.sex = e.sex;
            strcpy(q->data.tel,e.tel);
            return 1;

        }
        q = q->next;
    }

    
}


int list_delete_name(DoubleLoop L,char* name)
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
    int result = list_find_name(L,name);
    if (result <= 0)
    {
        printf("名字为%s的联系人未找到,删除信息失败\n",name);
        return -3;
    }
    //找到节点进行删除
    //定义遍历指针，从第一个节点出发
    DoubleLoop q = L->next;
    while (q!= L)
    {
        //进行对比
        if (strcmp(q->data.name,name) == 0)
        {
            printf("%s的信息已找到,开始进行删除\n",name);
            break;
        }
        q = q->next;
    }
    //开始进行删除节点q
    q->prior->next = q->next;
    q->next->prior = q->prior;

    free(q);
    q = NULL;

    L->len--;

    printf("%s的信息删除成功\n",name);
    
}


//按位置及给定信息插入
int list_insert_pos(DoubleLoop L,int pos,datatype e)
{
    if (NULL == L || pos < 0 || pos > L->len)
    {
        printf("所给链表不合法\n");
        return -1;
    }
    //构造插入节点
    DoubleLoop p = apply_node(e);
    if (NULL == p)
    {
        return -2;
    }
    
    //遍历到pos-1 位置
    //定义遍历指针，从头节点出发
    DoubleLoop q = L;
    while ( pos > 0)
    {
        q = q->next;
        pos--;
    }
    printf("插入节点前一个节点数据:%d\n",q->data.id);
    //以q为基准进行头插
    if (q->next == L)
    {
        p->next = q->next;
        q->next = p;
        p->prior = q;
        q->prior = p;

    } else
    {
        p->next = q->next;
        p->prior = q;
        q->next->prior= p;
        q->next = p;
    }
    L->len++;
    printf("%d位置插入成功\n",pos);
    
    
}

int export_info_to_file(DoubleLoop L)
{
    if (NULL == L)
    {
        printf("所给链表不合法\n");
        return -1;
    }

    if (getLength(L)==0)
    {
        printf("链表中未录入信息，不能进行导出\n");
        return -2;
    }
    
    //定义遍历指针，从第一个节点出发
    DoubleLoop q = L->next;
    //将链表中信息写入文件中
    FILE *fp = fopen("./contact.txt","w");
    if (NULL == fp)
    {
        printf("文件打开失败\n");
        return -1;
    }
    fprintf(fp,"%s\t%s\t%s\t%s\t\n","编号","姓名","性别","电话号码");
    while (q!= L)
    {
        //将信息保存到文件中
        
        fprintf(fp,"%d\t%s\t%c\t%s\t\n",q->data.id,q->data.name,q->data.sex,q->data.tel);
        //关闭文件
        q = q->next;
    }
    fclose(fp);
    return 0;
}


//获取链表长度
int getLength(DoubleLoop L)
{
    if (NULL == L)
    {
        printf("所给链表不合法\n");
        return -1;
    }
    return L->len;
}