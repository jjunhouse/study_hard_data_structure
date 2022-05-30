#include "arraygraph.h"

int addEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID)
{
    if (pGraph == NULL)
        return (ERROR);
    if (((pGraph->pVertex)[fromVertexID] == NOT_USED) \
        || ((pGraph->pVertex)[toVertexID] == NOT_USED))
        return (FALSE);
    (pGraph->ppAdjEdge)[fromVertexID][toVertexID] = 1;
    if (pGraph->graphType == GRAPH_UNDIRECTED)
        (pGraph->ppAdjEdge)[toVertexID][fromVertexID] = 1;
    return (SUCCESS);
}

int addEdgewithWeightAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID, int weight)
{
    if (pGraph == NULL)
        return (ERROR);
    if (((pGraph->pVertex)[fromVertexID] == NOT_USED) \
        || ((pGraph->pVertex)[toVertexID] == NOT_USED))
        return (FALSE);
    (pGraph->ppAdjEdge)[fromVertexID][toVertexID] = weight;
    if (pGraph->graphType == GRAPH_UNDIRECTED)
        (pGraph->ppAdjEdge)[toVertexID][fromVertexID] = weight;
    return (SUCCESS);
}
