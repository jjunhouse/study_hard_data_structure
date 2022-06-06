#include "arraygraph.h"


int isEmptyAG(ArrayGraph *pGraph)
{   
    // to consider AdjEdge
    // when free talking time, juhyuki will ask this problem.
    if (pGraph == NULL)
        return (ERROR);
    if ((pGraph->currentVertexCount) == 0)
        return (TRUE);
    return (FALSE);
}