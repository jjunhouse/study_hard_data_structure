#include "heap.h"

int	isHeapFull(maxHeap *Heap)
{
	if (!Heap)
		return (0);
	if (Heap->currentElementCount == Heap->maxElementCount - 1)
		return (1);
	return (0);
}
