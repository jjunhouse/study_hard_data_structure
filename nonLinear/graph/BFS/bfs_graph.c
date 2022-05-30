#include "bfs_graph.h"

void	setVertexes(ArrayGraph *mGraph)
{
	int	i;

	i = -1;
	while (++i < mGraph->maxVertexCount)
		addVertexAG(mGraph, i);
}

void	setEdges(ArrayGraph *mGraph)
{
	/*
	pdf example

	addEdgeAG(mGraph, 0, 1);
	addEdgeAG(mGraph, 0, 2);
	addEdgeAG(mGraph, 1, 3);
	addEdgeAG(mGraph, 1, 4);
	addEdgeAG(mGraph, 3, 7);
	addEdgeAG(mGraph, 4, 5);
	addEdgeAG(mGraph, 2, 5);
	addEdgeAG(mGraph, 2, 6);
	*/

	// https://freedeveloper.tistory.com/273
	addEdgeAG(mGraph, 0, 1);
	addEdgeAG(mGraph, 0, 2);
	addEdgeAG(mGraph, 0, 7);
	addEdgeAG(mGraph, 1, 6);
	addEdgeAG(mGraph, 2, 3);
	addEdgeAG(mGraph, 2, 4);
	addEdgeAG(mGraph, 6, 7);
	addEdgeAG(mGraph, 6, 5);
}

void	checkinVertex(LinkedQueue *mQueue, char *checkingV, int i)
{
	QueueNode	element;

	checkingV[i] = VISITED;
	printf("visit: [%d]\n", i);
	element.data = i;
	enqueLQ(mQueue, element);
}

//반복문으로 만듬
void    bfsGraph(ArrayGraph *mGraph)
{
	LinkedQueue	*mQueue;
	char		*checkingV;
	QueueNode	*tmp;
	int			i;

	mQueue = createLinkedQueue();
	checkingV = calloc(mGraph->maxVertexCount, sizeof(char));	
	checkinVertex(mQueue, checkingV, 0);
	while (isLinkedQueueEmpty(mQueue) == FALSE)
	{
		tmp = dequeLQ(mQueue);
		i = -1;
		while (++i < mGraph->maxVertexCount)
			if (mGraph->ppAdjEdge[tmp->data][i] > 0)
				if (checkingV[i] == NOT_VISITED)
					checkinVertex(mQueue, checkingV, i);
		free(tmp);
	}
	free(checkingV);
	deleteLinkedQueue(mQueue);
}

int main(void)
{
    ArrayGraph  *mGraph;

    printf("hello junhyuki!\n");

    // setting graph
    mGraph = createArrayGraph(8);
	displayArrayGraph(mGraph);

    setVertexes(mGraph);
	setEdges(mGraph);
	displayArrayGraph(mGraph);

    // dfs_graph();
	bfsGraph(mGraph);

	deleteArrayGraph(mGraph);

    return (0);
}
