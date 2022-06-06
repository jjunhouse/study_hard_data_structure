#ifndef GRAPH_ALGO_H
# define GRAPH_ALGO_H

#include "heap.h"
#include "arraygraph.h"
#include "dfs_graph.h"

#include "dijkstra.h"

void    kruskal(ArrayGraph *graph, ArrayGraph *MST);
void	prim(ArrayGraph *graph, ArrayGraph *PrimMST, int rootVertexID);

#endif