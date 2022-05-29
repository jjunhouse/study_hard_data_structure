#include "linkedgraph.h"

int removeEdgeLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID)
{
    ListNode    *tmp;
    int         to_position;

    if (pGraph == NULL)
        return (ERROR);
    to_position = -1;
    tmp = pGraph->ppAdjEdge[fromVertexID]->headerNode.pLink;
    while (tmp)
    {
        to_position += 1;
        if (tmp->data.vertexID == toVertexID)
            break ;
        tmp = tmp->pLink;
    }
    if (tmp == NULL)
        return (FALSE);
    removeLLElement(pGraph->ppAdjEdge[fromVertexID], to_position);
    if (pGraph->graphType == GRAPH_UNDIRECTED)
        removeEdgeLG(pGraph, toVertexID, fromVertexID);
    return (SUCCESS);
}
