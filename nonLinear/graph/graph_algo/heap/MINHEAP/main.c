#include <stdio.h>
#include "heap.h"

int	main(void)
{
	int			i;
	minHeap		*heap;
	minHeapNode	*node;
	minHeapNode	element;

	heap = createminHeap(11);
	printf("empty : %d\n", isHeapEmpty(heap));
	printf("full : %d\n", isHeapFull(heap));

	element.key = 7;
	insertminHeap(heap, element);
	element.key = 6;
	insertminHeap(heap, element);
	element.key = 5;
	insertminHeap(heap, element);
	element.key = 4;
	insertminHeap(heap, element);
	element.key = 3;
	insertminHeap(heap, element);
	element.key = 2;
	insertminHeap(heap, element);
	element.key = 1;
	insertminHeap(heap, element);
	/*element.key = 3;
	insertminHeap(heap, element);
	element.key = 2;
	insertminHeap(heap, element);
	element.key = 1;
	insertminHeap(heap, element);*/
		
	printf("empty : %d\n", isHeapEmpty(heap));
	printf("full : %d\n", isHeapFull(heap));
	i = 1;

	deleteminHeap(heap);
	//deleteminHeap(heap);
	while (i <= 7)
	{
		printf("i %d : %d\n", i, heap->pNode[i].key);
		i++;
	}
	return (0);
}
