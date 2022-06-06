#include "graph_algo.h"

void	set_groupID(ArrayGraph *MST, minHeapNode *poped, int *groupID)
{
	int	toGID;
	int	i;

	toGID = groupID[poped->toVertexID];
	i = -1;
	while (++i < MST->maxVertexCount)
	{
		if (groupID[i] == toGID)
			groupID[i] = groupID[poped->fromVertexID];
	}
}

void    kruskal(ArrayGraph *graph, ArrayGraph *MST)
{
	minHeap *PQ;
	minHeapNode PQ_node;
	minHeapNode *poped;
	int	*groupID;
	int	i;
	int	j;

	PQ = createminHeap(graph->currentVertexCount * graph->currentVertexCount / 2);
	i = -1;
	while (++i < graph->maxVertexCount)
	{
		j = i;
		while (++j < graph->maxVertexCount)
		{
			if (graph->ppAdjEdge[i][j] > 0)
			{
				PQ_node.key = graph->ppAdjEdge[i][j];
				PQ_node.fromVertexID = i;
				PQ_node.toVertexID = j;
				insertminHeap(PQ, PQ_node);
			}
		}
	}
	i = -1;
	while (++i < graph->maxVertexCount)
		addVertexAG(MST,i);
	groupID = calloc(MST->maxVertexCount, sizeof(int));
	i = -1;
	while (++i < MST->maxVertexCount)
		groupID[i] = i;
	while (isHeapEmpty(PQ) == FALSE)
	{
		poped = deleteminHeap(PQ);
		if (groupID[poped->fromVertexID] == groupID[poped->toVertexID])
		{
			free(poped);
			poped = NULL;
			continue ;
		}
		MST->ppAdjEdge[poped->fromVertexID][poped->toVertexID] = poped->key;
		MST->ppAdjEdge[poped->toVertexID][poped->fromVertexID] = poped->key;
		set_groupID(MST, poped, groupID);
		free(poped);
		poped = NULL;
	}
	printf("\n-----Kruskal algorithm-----\n");
	displayArrayGraph(MST);
	printf("-----done Kruskal-----\n\n");
}
