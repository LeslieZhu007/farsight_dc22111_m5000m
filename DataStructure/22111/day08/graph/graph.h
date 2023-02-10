#ifndef _GRAPH_H__
#define _GRAPH_H__
#include <stdio.h>
#include <stdlib.h>

#define N 5
typedef char datatype;

typedef struct
{
	datatype data[N];

	int rel[N][N];
} Graph;


//create
Graph* graph_create();

//add relation
void add_relation(Graph *G,datatype v1,datatype v2);

//show
void graph_show(Graph *G);



#endif
