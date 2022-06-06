#include "linkedgraph.h"

void *deleteLinkedGraph(LinkedGraph *pGraph)
{
    int i;

    if (pGraph == NULL)
        return (NULL);
    free(pGraph->pVertex);
    i = -1;
    while (++i < pGraph->maxVertexCount)
        deleteLinkedList(pGraph->ppAdjEdge[i]);
    return (NULL);
}