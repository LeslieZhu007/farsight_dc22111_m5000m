#if 0
#ifndef __TEST_H__
#define __TEST_H__

struct Node
{
    double value;
    int data;
};

#endif

#else

#pragma once  //2.类似于条件编译
struct Node
{
    double value;
    int data;
};


#endif