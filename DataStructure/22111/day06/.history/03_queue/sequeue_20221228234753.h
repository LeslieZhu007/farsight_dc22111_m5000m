#ifndef __SEQUEUE_H__

#define __SEQUEUE_H__
#define MAX 20

#include <stdio.h>
#include <unistd.h>



typedef int datatype;

struct sequeue
{
    datatype data[MAX];
    int front;
    int tail;
};



#endif