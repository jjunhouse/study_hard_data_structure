#include <stdlib.h>
#include "heap.h"

minHeap	*createminHeap(int maxsize)
{
	minHeap	*Heap;

	if (maxsize < 1)
		return (0);
	Heap = (minHeap *)malloc(sizeof(minHeap));
	if (!Heap)
		return (0);
	Heap->maxElementCount = maxsize;
	Heap->currentElementCount = 0;
	Heap->pNode = malloc(sizeof(minHeapNode) * (maxsize));
	if (!Heap->pNode)
	{
		free(Heap);
		Heap = 0;
		return (0);
	}
	return (Heap);
}
