#include "graph.h"


Graph *graph_create()
{

	Graph *G = (Graph *)malloc(sizeof(Graph));
	if(NULL == G)
	{
		printf("create failed\n");
		return NULL;

	}

	//ini top array
	for(int i=0;i<N;i++)
	{
		G->data[i] = 'A' + i;

	}

	//init rel array
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			G->rel[i][j] = 0;
		}

	}
	printf("create success\n");

	return G;

}



void graph_show(Graph *G)
{
	if(NULL == G)
	{
		printf("show failed\n");
		return;
	}

	//print
	for(int i=0;i<N;i++)
	{
		printf("\t%c",G->data[i]);
	}

	printf("\n");

	//print rel array
	for(int i=0;i<N;i++)
	{
		printf("%c\t",G->data[i]);
		for(int j=0;j<N;j++)
		{
			printf("%d\t",G->rel[i][j]);

		}
		printf("\n");
	}


}

//top dot index in the Graph
int get_pos(Graph *G,datatype v)
{
	if(NULL == G)
	{
		printf("get position failed\n");
		return -1;
	}

	for(int i=0;i<N;i++)
	{
		if(G->data[i] == v)
		{
			return i;
		}
	}
	return -1;
}

//add relationships
void add_relation(Graph *G,datatype v1,datatype v2)
{
	//find the top dot v1 v2's indexes
	int pos1 = get_pos(G,v1);
	int pos2 = get_pos(G,v2);

	if(NULL== G|| pos1 < 0 || pos2 < 0)
	{
		printf("establish relationships faliled\n");
		return;
	}

	//establish the relationships of the 2 top dots
	
	G->rel[pos1][pos2] = G->rel[pos2][pos1] = 1;

	printf("%c and %c relationships establish success\n",v1,v2);


	
}
