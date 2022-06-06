#include "arraygraph.h"

int addVertexAG(ArrayGraph *pGraph, int vertexID)
{
    if (pGraph == NULL)
        return (ERROR);
    if (vertexID > pGraph->maxVertexCount - 1)
        return (ERROR);
    (pGraph->pVertex)[vertexID] = USED;
    (pGraph->currentVertexCount) += 1; 
    return (SUCCESS);
}