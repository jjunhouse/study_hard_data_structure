#include "arraygraph.h"

int removeVertexAG(ArrayGraph *pGraph, int vertexID)
{
    int i;
    if (pGraph == NULL)
        return (ERROR);
    if (vertexID > pGraph->maxVertexCount - 1)
        return (ERROR);
    if (pGraph->pVertex[vertexID] == NOT_USED)
        return (FAIL);
    i = -1;
    while (++i < pGraph->maxVertexCount)
    {
        (pGraph->ppAdjEdge)[i][vertexID] = 0;
        (pGraph->ppAdjEdge)[vertexID][i] = 0;
    }
    pGraph->pVertex[vertexID] = NOT_USED;
    pGraph->currentVertexCount -= 1;
    return (SUCCESS);
}
