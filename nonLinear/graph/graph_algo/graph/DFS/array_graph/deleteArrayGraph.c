#include "arraygraph.h"

void *deleteArrayGraph(ArrayGraph *pGraph)
{
    int i;

    if (pGraph == NULL)
        return (NULL);
    i = -1;
    while (++i < pGraph->maxVertexCount)
    {
        if (pGraph->ppAdjEdge[i] == NULL)
            break ;
        free(pGraph->ppAdjEdge[i]);
    }
    free(pGraph->ppAdjEdge);
    free(pGraph->pVertex);
    free(pGraph);
    printf("삭제가 잘되었당!\n");
    return (NULL);
}
