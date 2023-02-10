#ifndef __SEQLIST_H__
#define __SEQLIST_H__
#define ERR_MSG(msg) do\
{\
    fprintf(stderr,"line:%d\n",__LINE__);\
    perror(msg);\
} while (0);
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//创建

//判空

//判满

//添加元素

//遍历

//任意位置插入


//任意位置删除





#endif