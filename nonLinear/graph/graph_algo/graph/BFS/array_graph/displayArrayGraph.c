#include "arraygraph.h"

void displayArrayGraph(ArrayGraph *pGraph)
{   
    int i;
    int j;
    printf("최대 노드 개수 %d\n", pGraph->maxVertexCount);
    printf("현재 사용 되는 노드의 개수 %d\n", pGraph->currentVertexCount);
    if (pGraph->graphType == 1)
        printf("그래프의 종류 undirected Graph\n");
    else
        printf("그래프의 종류 directed Graph\n");
    i = -1;
    while (++i < pGraph->maxVertexCount)
    {
        j = -1;
        while(++j < pGraph->maxVertexCount)
            printf("%d ", pGraph->ppAdjEdge[i][j]);
        printf("\n");
    }
}
