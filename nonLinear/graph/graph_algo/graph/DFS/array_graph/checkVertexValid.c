#include "arraygraph.h"

int checkVertexValid(ArrayGraph *pGraph, int vertexID)
{
    int flag_valid;
    int i;

    if (pGraph == NULL)
        return (ERROR);
    if ((pGraph->pVertex)[vertexID] == NOT_USED)
        return (FALSE);
    flag_valid = FALSE;
    i = -1;
    while (++i < pGraph->maxVertexCount)
    {
        if (pGraph->ppAdjEdge[i][vertexID] != 0)
            flag_valid = TRUE;
        if (pGraph->ppAdjEdge[vertexID][i] != 0)
            flag_valid = TRUE;
        if (flag_valid == TRUE)
            break ;
    }
    return (flag_valid);
}
