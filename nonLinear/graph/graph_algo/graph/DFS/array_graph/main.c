#include "arraygraph.h"

int main(void)
{
    ArrayGraph  *undir;
    int         i;

    undir = createArrayGraph(3);
    i = -1;
    while (++i < undir->maxVertexCount)
        addVertexAG(undir, i);
    addEdgeAG(undir, 0, 1);
    addEdgeAG(undir, 0, 2);
    addEdgeAG(undir, 1, 2);
    displayArrayGraph(undir);

    printf("\n");

    ArrayGraph  *dir;
    int         j;

    dir = createArrayDirectedGraph(3);
    j = -1;
    while (++j < dir->maxVertexCount)
        addVertexAG(dir, j);
    addEdgeAG(dir, 0, 1);
    addEdgeAG(dir, 0, 2);
    addEdgeAG(dir, 1, 2);
    displayArrayGraph(dir);
    return (0);
}