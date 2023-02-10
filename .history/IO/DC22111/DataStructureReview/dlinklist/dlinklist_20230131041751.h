#ifndef __DLINKLIST_H__
#define __DLINKLIST_H__
#define ERR_MSG(msg) do\
{\
    fprintf(stderr,"line:%d\n",__LINE__);\
    perror(msg);\
} while (0);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//创建


//头插

//遍历

//判空

//任意位置插

//头删


//任意位置删

//释放





#endif