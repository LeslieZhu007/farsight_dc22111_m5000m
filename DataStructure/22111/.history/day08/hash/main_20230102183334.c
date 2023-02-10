#include "hash.h"




int main(int argc, char const *argv[])
{
    int arr[] = {25,51,8,22,26,67,11,16,54,41};
    int len = sizeof(arr)/sizeof(arr[0]);
    
    //定义哈希表
    Node *hash[N];

    init_hash(hash);

    //将所有元素存储到哈希表中
    for (int i = 0; i < len; i++)
    {
        store_hash(hash,arr[i]);
    }
    

    return 0;
}
