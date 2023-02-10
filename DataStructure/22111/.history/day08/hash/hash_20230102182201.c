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
    //
}