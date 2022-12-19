#include <stdio.h>
#include <string.h>

typedef struct Test
{
    int value_a;
    int value_b;
    int value_c;

} *T1,T2;    //T1是结构体指针类型，T2是普通结构体变量类型

int main(int argc, char const *argv[])
{
    T1 m; //m是结构体指针变量 struct Test *m;
    T2 n; //n是普通结构体变量 struct Test n
    printf("sizeof m = %ld\n",sizeof(m)); //8 
    printf("sizeof n = %ld\n",sizeof(n));
    m = &n;
    return 0;
}
