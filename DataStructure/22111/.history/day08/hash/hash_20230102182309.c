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
    int pos = key/N; //使用除留余数法
}