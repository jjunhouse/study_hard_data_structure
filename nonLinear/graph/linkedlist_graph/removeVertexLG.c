#include "linkedgraph.h"

int removeVertexLG(LinkedGraph *pGraph, int vertexID)
{
    int i;

    if (pGraph == NULL)
        return (ERROR);
    i = -1;
    while (++i < pGraph->maxVertexCount)
        if (pGraph->pVertex[i] == USED)
            removeEdgeLG(pGraph, i, vertexID);
    pGraph->pVertex[vertexID] = NOT_USED;
    deleteLinkedList(pGraph->ppAdjEdge[vertexID]);
    (pGraph->currentVertexCount)--;
    return (SUCCESS);
}
