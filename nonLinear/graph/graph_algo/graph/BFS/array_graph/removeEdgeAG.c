#include "arraygraph.h"

int removeEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID)
{
    if (pGraph == NULL)
        return (ERROR);
    if (pGraph->pVertex[fromVertexID] == NOT_USED \
        || pGraph->pVertex[fromVertexID] == NOT_USED)
        return (FALSE);
    (pGraph->ppAdjEdge)[fromVertexID][toVertexID] = 0;
    if (pGraph->graphType == GRAPH_UNDIRECTED)
        (pGraph->ppAdjEdge)[toVertexID][fromVertexID] = 0;
    return (SUCCESS);
}
