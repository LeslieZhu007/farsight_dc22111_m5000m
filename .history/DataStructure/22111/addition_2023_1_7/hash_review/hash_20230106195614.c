#include "hash.h"


//初始化哈希表
void init_hash(Node **hash)
{
    for (int i = 0; i < N; i++)
    {
        hash[i] = NULL;
    }
    
}


//哈希存储
void store_hash(Node **hash,int key)
{
    //确定要存储的链表
    int pos = key%N; //使用除留余数法构造哈希函数

    //该元素要存储的是hash[pos]表示的链表中
    //申请节点封装数据
    Node *p = (Node *)malloc(sizeof(Node));
    if (NULL == p)
    {
        printf("节点申请失败\n");
        return;
    }
    p->data = key;
    p->next = NULL;
     
    //使用头插法，将节点插入到该链表中 hash[pos]  
    // hash[pos]本身是一个指针

    //带头指针的头插，没有头节点
    




}