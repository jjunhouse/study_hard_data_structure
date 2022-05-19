#include "heap.h"

int	insertminHeap(minHeap *Heap, minHeapNode element)
{
	int	i;

	if (!Heap || isHeapFull(Heap))
		return (0);
	i = Heap->currentElementCount + 1;
	while ((i != 1) && (element.key < Heap->pNode[i / 2].key))
	{
		Heap->pNode[i] = Heap->pNode[i / 2];
		i /= 2;
	}
	Heap->pNode[i].key = element.key;
	Heap->currentElementCount++;
	return (1);
}
