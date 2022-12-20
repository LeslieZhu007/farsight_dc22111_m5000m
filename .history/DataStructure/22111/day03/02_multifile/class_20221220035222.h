#ifndef __CLASS_H__
#define __CLASS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

/*
 * 注意scanf的垃圾字符处理问题
*/
typedef struct Student
{
    char name[20];
    char id;    //身份  S：学生    T: 老师
    union 
    {
        double score;
        char subject[10];
    };
} Stu;

//定义班级结构体
typedef struct Class
{
    struct Student s[MAX]; //学生数组
    int count;     //表示当前班级的人数
} clsSeqList;


double input(clsSeqList *cls);

void output(clsSeqList *cls);

clsSeqList * create_class();

int class_empty(clsSeqList *cls);

int class_full(clsSeqList *cls);

int class_add(clsSeqList *cls,Stu s);

int class_insert_pos(clsSeqList *cls,int pos,Stu s);

int class_delete_pos(clsSeqList *cls,int pos);

#endif