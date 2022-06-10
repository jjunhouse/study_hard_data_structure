#include "graph_algo.h"

static int areAllVertices(ArrayGraph *graph)
{
	int	i;

	i = -1;
	while (++i < graph->maxVertexCount)
	{
		if (graph->pVertex[i] == NOT_USED)
			return (FALSE);
	}
	return (TRUE);
}

static void	setAdjEdgeToPQ(ArrayGraph *graph, ArrayGraph *PrimMST, minHeap *PQ, int fromVertexID)
{
	minHeapNode element;
	int	toVertexID;
	int	i;

	i = -1;
	while (++i < graph->maxVertexCount)
	{
		if (graph->ppAdjEdge[fromVertexID][i] > 0 && PrimMST->pVertex[i] == NOT_USED)
		{
			element.key = graph->ppAdjEdge[fromVertexID][i];
			element.fromVertexID = fromVertexID;
			element.toVertexID = i;
			insertminHeap(PQ, element);
		}
	}
}

void	prim(ArrayGraph *graph, ArrayGraph *PrimMST, int rootVertexID)
{
	minHeap *PQ;
	minHeapNode PQ_node;
	minHeapNode *poped;

	PQ = createminHeap(PrimMST->maxVertexCount * PrimMST->maxVertexCount / 2);
	addVertexAG(PrimMST, rootVertexID);
	setAdjEdgeToPQ(graph, PrimMST, PQ, rootVertexID);
	while (areAllVertices(PrimMST) == FALSE && (isHeapEmpty(PQ) == FALSE))
	{
		poped = deleteminHeap(PQ);
		if (PrimMST->pVertex[poped->toVertexID] == NOT_USED)
		{
			addVertexAG(PrimMST, poped->toVertexID);
			addEdgewithWeightAG(PrimMST, poped->fromVertexID, poped->toVertexID, poped->key);
			setAdjEdgeToPQ(graph, PrimMST, PQ, poped->toVertexID);
		}
		free(poped);
	}
	printf("\n-----Prim algorithm-----\n");
	displayArrayGraph(PrimMST);
	printf("-----done Prim-----\n");
}
