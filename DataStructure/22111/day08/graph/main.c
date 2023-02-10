#include "graph.h"


int main()
{

	Graph *G = graph_create();
	if(NULL == G)
	{
		return -1;
	}
	
	printf("info in the graph is:\n");
	graph_show(G);

	add_relation(G,'A','B');
	add_relation(G,'A','D');
	add_relation(G,'B','C');
	add_relation(G,'C','D');
	add_relation(G,'C','E');
	printf("info in the graph is:\n");
	graph_show(G);
	return 0;
}

