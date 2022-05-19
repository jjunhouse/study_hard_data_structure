#include "heap.h"

int	isHeapFull(minHeap *Heap)
{
	if (!Heap)
		return (0);
	if (Heap->currentElementCount == Heap->maxElementCount - 1)
		return (1);
	return (0);
}
