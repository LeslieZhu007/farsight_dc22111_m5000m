#include <stdio.h>
#define MAX 20

int main(int argc, char const *argv[])
{
    
    printf("max=%d\n",MAX);
#undef MAX  //取消宏名定义
    //printf("max=%d\n",MAX); 报错

#define MAX 100
    printf("max=%d\n",MAX);


    return 0;
}
