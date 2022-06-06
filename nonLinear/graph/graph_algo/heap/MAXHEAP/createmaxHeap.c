#include <stdlib.h>
#include "heap.h"

maxHeap	*createmaxHeap(int maxsize)
{
	maxHeap	*Heap;

	if (maxsize < 1)
		return (0);
	Heap = (maxHeap *)malloc(sizeof(maxHeap));
	if (!Heap)
		return (0);
	Heap->maxElementCount = maxsize;
	Heap->currentElementCount = 0;
	Heap->pNode = malloc(sizeof(maxHeapNode) * (maxsize));
	if (!Heap->pNode)
	{
		free(Heap);
		Heap = 0;
		return (0);
	}
	return (Heap);
}
