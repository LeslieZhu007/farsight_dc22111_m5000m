#ifndef __HASH_H__
#define __HASH_H__
#define N 13
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//定义节点类型
typedef int datatype;
typedef struct Node
{
    datatype data;
    struct Node *next;
} Node;

//初始化哈希表
void init_hash(Node **hash); //Node *hash[]

//哈希存储
void store_hash(Node **hash,int key);

//展示哈希表
void show_hash(Node **hash);

//哈希查找
void search_hash(Node *hash[],datatype key);





#endif