#include "arraygraph.h"

ArrayGraph *createArrayGraph(int maxVertexCount)
{
    ArrayGraph  *ret;
    int         i;

    ret = calloc(1, sizeof(ArrayGraph));
    if (ret == NULL)
        return (NULL);
    ret->maxVertexCount = maxVertexCount;
    ret->graphType = GRAPH_UNDIRECTED;
    ret->ppAdjEdge = calloc(maxVertexCount, sizeof(int *));
    if (ret->ppAdjEdge == NULL)
    {
        free(ret);
        return (NULL);
    }
    i = -1;
    while (++i < maxVertexCount)
    {
        (ret->ppAdjEdge)[i] = calloc(maxVertexCount, sizeof(int));
        if (ret->ppAdjEdge[i] == NULL)
            return (deleteArrayGraph(ret));
    }
    ret->pVertex = calloc(maxVertexCount, sizeof(int));
    if (ret->pVertex == NULL)
        return (deleteArrayGraph(ret));
    return (ret);
}


ArrayGraph *createArrayDirectedGraph(int maxVertexCount)
{
    ArrayGraph  *ret;
    int         i;

    ret = calloc(1, sizeof(ArrayGraph));
    if (ret == NULL)
        return (NULL);
    ret->maxVertexCount = maxVertexCount;
    ret->graphType = GRAPH_DIRECTED;
    ret->ppAdjEdge = calloc(maxVertexCount, sizeof(int *));
    if (ret->ppAdjEdge == NULL)
    {
        free(ret);
        return (NULL);
    }
    i = -1;
    while (++i < maxVertexCount)
    {
        (ret->ppAdjEdge)[i] = calloc(maxVertexCount, sizeof(int));
        if (ret->ppAdjEdge[i] == NULL)
            return (deleteArrayGraph(ret));
    }
    ret->pVertex = calloc(maxVertexCount, sizeof(int));
    if (ret->pVertex == NULL)
        return (deleteArrayGraph(ret));
    return (ret);
}