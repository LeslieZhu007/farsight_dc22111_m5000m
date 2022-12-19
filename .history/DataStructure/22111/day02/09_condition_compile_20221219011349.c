#include <stdio.h>
#define MAX 20

int main(int argc, char const *argv[])
{
    
    printf("max=%d\n",MAX);
#undef MAX  //取消宏名定义
    //printf("max=%d\n",MAX); 报错

#define MAX 100
    printf("max=%d\n",MAX);

    //条件编译
#if 0
    printf("hello world\n");
#else
    printf("hello world 007\n");
#endif


#if 0
    hello usa
#endif

/*************************************/

#ifdef MAX
    printf("MAX is already defined\n");

#endif

#ifndef SUM
    printf("SUM is not defined\n");
#endif



    return 0;
}
