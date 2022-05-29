#include "linkedgraph.h"

LinkedGraph *createLinkedGraph(int maxVertexCount)
{
    LinkedGraph *ret;

    ret = calloc(1, sizeof(LinkedGraph));
    if (ret == NULL)
        return (NULL);
    ret->maxVertexCount = maxVertexCount;
    ret->graphType = GRAPH_UNDIRECTED;
    ret->pVertex = calloc(maxVertexCount, sizeof(int));
    if (ret->pVertex == NULL)
    {
        // todo: deleteLinkedGraph;
        return (NULL);
    }
    ret->ppAdjEdge = calloc(maxVertexCount, sizeof(LinkedList *));
    return (ret);
}

LinkedGraph *createArrayDirectedGraph(int maxVertexCount)
{
    LinkedGraph *ret;

    ret = calloc(1, sizeof(LinkedGraph));
    if (ret == NULL)
        return (NULL);
    ret->maxVertexCount = maxVertexCount;
    ret->graphType = GRAPH_DIRECTED;
    ret->pVertex = calloc(maxVertexCount, sizeof(int));
    if (ret->pVertex == NULL)
    {
        // todo: deleteLinkedGraph;
        return (NULL);
    }
    ret->ppAdjEdge = calloc(maxVertexCount, sizeof(LinkedList *));
    return (ret);
}
