#include <stdio.h>
#pragma pack(4)   //修改默认对齐系数
//#pragma pack(4) 
//64位操作系统默认对齐系数是8

typedef struct
{
    char a; //1
            //3
    int b; //4
    short c; //2
    char d;   //1
              //1
};   //12

//结构体大小是默认对齐系数8，与结构体中成员最大对齐系数4，选小的对齐系数的倍数


typedef struct
{
    char a; //1
            //3
    int b; //4
    double e;  // 8
    char d;    //1
};   //24

typedef struct
{
    int a ;  //4
    char name[13]; //13  对齐系数是1
};   //20

typedef struct
{
    char name[13]; //13  对齐系数是1
};   //13