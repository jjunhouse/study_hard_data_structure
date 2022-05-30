#include "dfs_graph.h"

void	setVertexes(ArrayGraph *jGraph)
{
	int	i;

	i = -1;
	while (++i < jGraph->maxVertexCount)
		addVertexAG(jGraph, i);
}

void	setEdges(ArrayGraph *jGraph)
{
	/*
	pdf example

	addEdgeAG(jGraph, 0, 1);
	addEdgeAG(jGraph, 0, 2);
	addEdgeAG(jGraph, 1, 3);
	addEdgeAG(jGraph, 1, 4);
	addEdgeAG(jGraph, 3, 7);
	addEdgeAG(jGraph, 4, 5);
	addEdgeAG(jGraph, 2, 5);
	addEdgeAG(jGraph, 2, 6);
	*/

	// https://freedeveloper.tistory.com/273
	addEdgeAG(jGraph, 0, 1);
	addEdgeAG(jGraph, 0, 2);
	addEdgeAG(jGraph, 0, 7);
	addEdgeAG(jGraph, 1, 6);
	addEdgeAG(jGraph, 2, 3);
	addEdgeAG(jGraph, 2, 4);
	addEdgeAG(jGraph, 6, 7);
	addEdgeAG(jGraph, 6, 5);
}

//재귀로 만듬
void    dfsGraph(ArrayGraph *jGraph, char *checkingV, int i)
{
    int j;

    checkingV[i] = VISITED;
	printf("visit: [%d]\n", i);
    j = -1;
    while (++j < jGraph->maxVertexCount)
        if (jGraph->ppAdjEdge[i][j] > 0)
            if(checkingV[j] == NOT_VISITED)
                dfsGraph(jGraph, checkingV, j);
}

int main(void)
{
    ArrayGraph  *jGraph;
    char    *checkingV;
    printf("with mgo\n");

    //그래프 만들기
     // setting graph
    jGraph = createArrayGraph(8);
	displayArrayGraph(jGraph);

    setVertexes(jGraph);
	setEdges(jGraph);
	displayArrayGraph(jGraph);
    checkingV = calloc(jGraph->maxVertexCount, sizeof(char));	

    dfsGraph(jGraph, checkingV, 0);

    free(checkingV);
    deleteArrayGraph(jGraph);
    return (0);
}