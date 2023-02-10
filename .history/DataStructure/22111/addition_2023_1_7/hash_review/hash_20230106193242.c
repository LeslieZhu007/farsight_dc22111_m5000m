#include "hash.h"


//初始化哈希表
void init_hash(Node **hash)
{
    for (int i = 0; i < N; i++)
    {
        hash[i] = NULL;
    }
    
}