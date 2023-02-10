#include <stdio.h>
//#pragma pack(1)  //改变计算机的系统内存对齐方式

struct Test
{
    double value; // 8
    char data; //1 
}; //16

int main(int argc, char const *argv[])
{
    printf("struct of struct Test=%ld\n",sizeof(struct Test));
    


    return 0;
}
