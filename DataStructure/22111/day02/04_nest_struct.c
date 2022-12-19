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
    struct T1 t[2]; 
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

    temp.t[1].value_a = 2;
    temp.t[1].value_b = 3;

    //定义结构体指针
    struct T2 *p = &temp;

    p->value_c = 1;
    p->t; //表示结构体变量的第二个成员数组的首地址
    p->t[0];
    p->t[1];
    p->t[0].value_a = 2;
    p->t[0].value_b = 3;

    p->t[1].value_a = 2;
    p->t[1].value_b = 3;

    //定义结构体数组
    struct T2 arr[2];  //arr[0],arr[1]
    (arr[0]).value_c = 1;
    (arr[0]).t; //表示结构体变量的第二个成员数组的首地址
    (arr[0]).t[0];
    (arr[0]).t[1];
    (arr[0]).t[0].value_a = 2;
    (arr[0]).t[0].value_b = 3;

    (arr[0]).t[1].value_a = 2;
    (arr[0]).t[1].value_b = 3;

    (arr+0)->t[0].value_a = 4;
    (&arr[0])->t[0].value_b = 5;
    (arr+1)->t[0].value_a = 6;
    (arr+1)->t[0].value_b = 7;
    

    return 0;
}
