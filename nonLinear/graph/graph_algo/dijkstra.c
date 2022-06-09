#include "dijkstra.h"

static int	findID(ArrayGraph *DijkstraPath, t_dijk *d_arr, int *checkingID)
{
	int	i;

	i = -1;
	while (++i < DijkstraPath->maxVertexCount)
	{
		if ((d_arr[i].distance != D_INFINITY) && (checkingID[i] == NOT_USED))
			return (i);
	}
	return (-1);
}

void	dijkstra(ArrayGraph *graph, ArrayGraph *DijkstraPath, int startVertexID)
{
	t_dijk	*d_arr;
	int	currentID;
	int	*checkingID;
	int	i;

	d_arr = calloc(graph->maxVertexCount, sizeof(t_dijk));
	checkingID = calloc(graph->maxVertexCount, sizeof(int));
	// 안해

	// init
	i = -1;
	while (++i < graph->maxVertexCount)
	{
		d_arr[i].distance = D_INFINITY;
		d_arr[i].waypointID = startVertexID;
	}
	d_arr[startVertexID].distance = 0;
	addVertexAG(DijkstraPath, startVertexID);
	
	currentID = startVertexID;
	while (currentID != -1)
	{
		checkingID[currentID] = USED;
		i = -1;
		while (++i < graph->maxVertexCount)
		{
			if (graph->ppAdjEdge[currentID][i] > 0)
			{
				if (d_arr[i].distance == D_INFINITY)
				{
					addVertexAG(DijkstraPath, i);
					d_arr[i].distance = d_arr[currentID].distance + graph->ppAdjEdge[currentID][i];
					d_arr[i].waypointID = currentID;
					addEdgewithWeightAG(DijkstraPath, currentID, i, graph->ppAdjEdge[currentID][i]);
				}
				else if (d_arr[i].distance > d_arr[currentID].distance + graph->ppAdjEdge[currentID][i])
				{
					removeEdgeAG(DijkstraPath, d_arr[i].waypointID, i);
					d_arr[i].distance = d_arr[currentID].distance + graph->ppAdjEdge[currentID][i];
					d_arr[i].waypointID = currentID;
					addEdgewithWeightAG(DijkstraPath, currentID, i, graph->ppAdjEdge[currentID][i]);
				}
			}
		}
		currentID = findID(DijkstraPath, d_arr, checkingID);
	}
	printf("\n-----Dijkstra algorithm-----\n");
	displayArrayGraph(DijkstraPath);
	printf("-----done Dijkstra-----\n");
}
