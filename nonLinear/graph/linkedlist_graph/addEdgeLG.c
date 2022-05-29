#include "linkedgraph.h"

int addEdgeLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID)
{
    LinkedList  *fVIDList;
    ListNode    *tmp;
    ListNode    elem;

    if (pGraph == NULL)
        return (ERROR);
    if (((pGraph->pVertex)[fromVertexID] == NOT_USED) \
        || ((pGraph->pVertex)[toVertexID] == NOT_USED))
        return (FALSE);
    fVIDList = pGraph->ppAdjEdge[fromVertexID];
    tmp = fVIDList->headerNode.pLink;
    while (tmp)
    {
        if (tmp->data.vertexID == toVertexID)
            return (FALSE);
        tmp = tmp->pLink;
    }
    elem.data.vertexID = toVertexID;
    elem.data.weight = 1;
    elem.pLink = NULL;
    // problem!: considering order?
    addLLElement(fVIDList, fVIDList->currentElementCount, elem);
    if (pGraph->graphType == GRAPH_UNDIRECTED)
        addEdgeLG(pGraph, toVertexID, fromVertexID);
    return (SUCCESS);
}

int addEdgewithWeightLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID, int weight)
{
    LinkedList  *fVIDList;
    ListNode    *tmp;
    ListNode    elem;

    if (pGraph == NULL)
        return (ERROR);
    if (((pGraph->pVertex)[fromVertexID] == NOT_USED) \
        || ((pGraph->pVertex)[toVertexID] == NOT_USED))
        return (FALSE);
    fVIDList = pGraph->ppAdjEdge[fromVertexID];
    tmp = fVIDList->headerNode.pLink;
    while (tmp)
    {
        if (tmp->data.vertexID == toVertexID)
            return (FALSE);
        tmp = tmp->pLink;
    }
    elem.data.vertexID = toVertexID;
    elem.data.weight = weight;
    elem.pLink = NULL;
    // problem!: considering order?
    addLLElement(fVIDList, fVIDList->currentElementCount, elem);
    if (pGraph->graphType == GRAPH_UNDIRECTED)
        addEdgewithWeightLG(pGraph, toVertexID, fromVertexID, weight);
    return (SUCCESS);
}
