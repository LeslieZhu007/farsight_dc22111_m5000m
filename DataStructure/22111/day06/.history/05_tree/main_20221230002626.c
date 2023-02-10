#include "btree.h"



int main(int argc, char const *argv[])
{
    
    //创建
    btree* B = tree_create();
    if (NULL == B)
    {
        return -1;
    } else
    {
        printf("创建成功\n");
    }
    

   tree_show(B);

   printf("\n");
    return 0;
}
