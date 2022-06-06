#include "graph_algo.h"

static ArrayGraph *createAndSetGraph()
{
    ArrayGraph* graph;

	graph = createArrayGraph(9);
    addVertexAG(graph,0);
    addVertexAG(graph,1);
    addVertexAG(graph,2);
    addVertexAG(graph,3);
    addVertexAG(graph,4);
    addVertexAG(graph,5);
    addVertexAG(graph,6);
    addVertexAG(graph,7);
    addVertexAG(graph,8);

    addEdgewithWeightAG(graph, 0, 1, 35);
    addEdgewithWeightAG(graph, 0, 4, 247);

    addEdgewithWeightAG(graph, 1, 2, 126);
    addEdgewithWeightAG(graph, 1, 5, 150);

    addEdgewithWeightAG(graph, 2, 3, 117);
    addEdgewithWeightAG(graph, 2, 5, 162);
    addEdgewithWeightAG(graph, 2, 6, 220);

    addEdgewithWeightAG(graph, 4, 5, 82);
    addEdgewithWeightAG(graph, 4, 7, 98);

    addEdgewithWeightAG(graph, 5, 6, 154);
    addEdgewithWeightAG(graph, 5, 7, 120);

    addEdgewithWeightAG(graph, 6, 8, 106);

    return (graph);
}

int main(void)
{
    ArrayGraph* graph		= createAndSetGraph();
    ArrayGraph* PrimMST		= createArrayGraph(9);
    ArrayGraph* KruskalMST	= createArrayGraph(9);
	ArrayGraph* DijkstraPath	= createArrayDirectedGraph(9);
    
	printf("----- just Graph -----\n");
    displayArrayGraph(graph);
	printf("----- just Graph -----\n");

	kruskal(graph, KruskalMST);
	prim(graph, PrimMST, 1);
	dijkstra(graph, DijkstraPath, 1);
	//Floyd

    return (0);
}
