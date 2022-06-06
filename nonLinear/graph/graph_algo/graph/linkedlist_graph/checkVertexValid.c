#include "linkedgraph.h"

int checkVertexValid(LinkedGraph *pGraph, int vertexID)
{
    if (pGraph == NULL)
        return (ERROR);
    if (pGraph->pVertex[vertexID] == NOT_USED)
        return (FALSE);
    if (pGraph->ppAdjEdge[vertexID]->currentElementCount == 0)
        return (FALSE);
    return (TRUE);
}