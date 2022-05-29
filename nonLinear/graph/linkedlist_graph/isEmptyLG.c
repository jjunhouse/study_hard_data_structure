#include "linkedgraph.h"

int isEmptyLG(LinkedGraph *pGraph)
{
    if (pGraph == NULL)
        return (ERROR);
    if ((pGraph->currentVertexCount) == 0)
        return (TRUE);
    return (FALSE);
}
