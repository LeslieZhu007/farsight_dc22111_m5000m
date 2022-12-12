#include <stdio.h>

typedef struct 
{
    int *data;
    int maxlen;
    int top;
} seqstack_t;

seqstack_t * create_stack(int len)
{
    seqstack_t * ss = (seqstack_t *) malloc(sizeof(seqstack_t));
    ss->data = malloc(sizeof(int)*len);
    ss->maxlen = len;
    ss->top = 0;
    return ss;
}

void clear_stack(seqstack_t *s)
{
    s->top = 0;
}

int EmptyStack(seqstack_t *s)
{
    //return (s->top==0)?1:0;
    return (s->top==0);
}


int main(int argc, char const *argv[])
{
    
    






    return 0;
}
