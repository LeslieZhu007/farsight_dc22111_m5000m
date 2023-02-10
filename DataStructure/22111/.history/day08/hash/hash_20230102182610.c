#include "hash.h"


//初始化哈希表
void init_hash(Node *hash[])
{
    for (int i = 0; i < N; i++)
    {
        hash[i] = NULL;
    }
    printf("初始化成功\n");
}

//哈希存储
void store_hash(Node *hash[],int key)
{
    //1.确定存储的链表
    int pos = key/N; //使用除留余数法构造哈希函数

    //申请节点封装数据
    Node *p = (Node *)malloc(sizeof(Node));
    if (NULL == p)
    {
        printf("节点申请失败\n");
        return;
    }
    
    p->data = key;
    p->next = NULL;

}