#include "heap.h"
#include <stdlib.h>

minHeapNode	*deleteminHeap(minHeap *Heap)
{
	int			i;
	int			parent;
	int			child;
	minHeapNode	*item;
	minHeapNode	*temp;

	if (isHeapEmpty(Heap))
		return (0);
	item = calloc(1, sizeof(minHeapNode));
	if (item == NULL)
		return (NULL);
	//item = &(Heap->pNode[1]);
	*item = Heap->pNode[1];
	temp = &(Heap->pNode[Heap->currentElementCount]);
	Heap->currentElementCount--;
	parent = 1;
	child = 2;
	while (child <= Heap->currentElementCount)
	{
		if ((child < Heap->currentElementCount) && (Heap->pNode[child].key > Heap->pNode[child + 1].key))
			child++;
		if (temp->key <= Heap->pNode[child].key)
			break;
		Heap->pNode[parent] = Heap->pNode[child];
		parent = child;
		child *= 2;
	}
	Heap->pNode[parent] = *temp;
	temp->key = 0;
	return (item);
}
