#include <stdio.h>
#pragma pack(4)  //改变计算机的系统内存对齐方式  12

struct Test
{
    double value; // 8
    char data; //1 
}; //12

#pragma pack()    //恢复系统默认的对齐方式

struct Test1
{
    double value; // 8
    char data; //1 
}; //16

#pragma pack(2)
struct Test2
{
    double value; // 8
    char data; //1 
};


int main(int argc, char const *argv[])
{
    printf("struct of struct Test=%ld\n",sizeof(struct Test)); //12
    printf("struct of struct Test1=%ld\n",sizeof(struct Test1)); //16
    printf("struct of struct Test2=%ld\n",sizeof(struct Test2));

    return 0;
}
