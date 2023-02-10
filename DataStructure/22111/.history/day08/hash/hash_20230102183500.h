#ifndef __HASH_H__
#define __HASH_H__
#include <stdio.h>
#include <stdlib.h>
#define N 13

typedef int datatype;

typedef struct Node
{
    datatype data; //数据域
    struct Node *next; //指针域

} Node;

//初始化哈希表
void init_hash(Node *hash[]);

//哈希存储
void store_hash(Node *hash[],int key);

//展示哈希表

//哈希查找

#endif