#include "linkqueue.h"




int main(int argc, char const *argv[])
{
    //创建
    linkqueue *L = queue_create();
    if (NULL == L)
    {
        return -1;
    }
    //入队
    queue_push(L,1);
    queue_push(L,2);
    queue_push(L,3);
    queue_push(L,4);
    queue_push(L,5);
       

    //遍历
    queue_show(L);

    //出队
    queue_pop(L);
    queue_pop(L);
    queue_pop(L);
    queue_pop(L);
    queue_pop(L);
    queue_pop(L);

    queue_show(L);
  
    //求返回队列长度

    //销毁

    return 0;
}
