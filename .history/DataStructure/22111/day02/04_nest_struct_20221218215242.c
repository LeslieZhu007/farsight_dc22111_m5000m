#include <stdio.h>
#include <string.h>
struct T1
{
    int value_a;
    int value_b;
};

struct T2
{
    int value_c;
    struct T1 t[2]; //
};

int main(int argc, char const *argv[])
{
    struct T2 temp;

    temp.value_c = 1;
    temp.t; //表示结构体变量的第二个成员数组的首地址
    temp.t[0];
    temp.t[1];
    temp.t[0].value_a = 2;
    temp.t[0].value_b = 3;
    

    return 0;
}
