#include "looplinklist.h"

//k为要删除的第几个数
void joseph_ring_function(LoopLinkList L,int k)
{
    //有多少个节点就删除多少次
    if (NULL == L)
    {
        return;
    }
    //循环次数为链表长度
    int count = L->len;
    LoopLinkList new_k = L;
    printf("count = %d\n",count);
    for(int i = 0;i < count;i++)
    {
        //循环k-1次找到要删除节点的前一个节点
        for(int j=0;j<k-1;j++)
        {
            new_k = new_k->next;
            //如果找到的是头节点，绕过
            if (new_k == L)
            {
                j--;
            }
        }
        
        LoopLinkList q = new_k->next;
        //如果要删除的是q是头节点，绕过
        if(q == L)
        {
            q = L->next;  
            //加上 new_k = L;
        }
        //打印数值
        printf("%d\t",q->data);
        //删除节点
    
        new_k->next = q->next;
        free(q);
        L->len--;
    }

    printf("\n");
    
    
}

int main(int argc, char const *argv[])
{
    //首先新建一个单向循环链表
    LoopLinkList L = list_create();
    //插入数据
    for (int i = 8; i > 0; i--)
    {
        list_insert_head(L,i);
    }
    list_show(L);
    

    joseph_ring_function(L,4);  
    //joseph_ring_headoff(L,4);



    return 0;
}
