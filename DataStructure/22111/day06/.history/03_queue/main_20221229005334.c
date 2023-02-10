#include "sequeue.h"


int main(int argc, char const *argv[])
{
    sequeue *q =  queue_create();
    if (NULL == q)
    {
        return -1;
    }
    
    //只能入队7个
    queue_push(q,4);
    queue_push(q,8);
    queue_push(q,3);
    queue_push(q,2);


    queue_show(q);


    queue_pop(q);
    
    return 0;
}
