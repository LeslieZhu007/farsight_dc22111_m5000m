#ifndef __CLASS_H__
#define __CLASS_H__

#include <stdio.h>
#include <stdlib.h>
#define MAX 20

/*
 * 注意scanf的垃圾字符处理问题
*/
struct Student
{
    char name[20];
    char id;    //身份  S：学生    T: 老师
    union 
    {
        double score;
        char subject[10];
    };
};

//定义班级结构体
struct Class
{
    struct Student s[MAX]; //学生数组
    int count;     //表示当前班级的人数
};


double input(struct Class *cls,int sum);

void output(struct Class *cls,int sum);


#endif