#include "heap.h"

int	isHeapEmpty(maxHeap *Heap)
{
	if (!Heap)
		return (0);
	if (Heap->currentElementCount == 0)
		return (1);
	return (0);
}
