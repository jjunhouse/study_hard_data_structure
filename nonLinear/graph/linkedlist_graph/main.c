#include "linkedgraph.h"

int main(void)
{
    LinkedGraph  *undir;
    int         i;

    undir = createLinkedGraph(3);
    i = -1;
    while (++i < undir->maxVertexCount)
        addVertexLG(undir, i);
    addEdgeLG(undir, 0, 1);
    addEdgeLG(undir, 0, 2);
    addEdgeLG(undir, 1, 2);
    //displayLinkedGraph(undir);

    printf("\n");

    LinkedGraph  *dir;
    int         j;

    dir = createArrayDirectedGraph(3);
    j = -1;
    while (++j < dir->maxVertexCount)
        addVertexLG(dir, j);
    addEdgeLG(dir, 0, 1);
    addEdgeLG(dir, 0, 2);
    addEdgeLG(dir, 1, 2);
    //displayLinkedGraph(dir);
    return (0);
}
