#include "linkedgraph.h"

int addVertexLG(LinkedGraph *pGraph, int vertexID)
{
    LinkedList  *new;

    if (pGraph == NULL)
        return (ERROR);
    if (vertexID > pGraph->maxVertexCount - 1)
        return (ERROR);
    if ((pGraph->pVertex)[vertexID] == USED)
        return (FALSE);
    new = createLinkedList();
    if (new == NULL)
    {
        // todo: delete
        return (ERROR);
    }
    new->headerNode.data.vertexID = vertexID;
    pGraph->ppAdjEdge[vertexID] = new;
    (pGraph->pVertex)[vertexID] = USED;
    (pGraph->currentVertexCount) += 1;
    return (SUCCESS);
}