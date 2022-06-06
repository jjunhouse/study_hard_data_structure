#include <stdio.h>
#include "heap.h"

int	main(void)
{
	int			i;
	maxHeap		*heap;
	maxHeapNode	*node;
	maxHeapNode	element;

	heap = createmaxHeap(11);
	//printf("empty : %d\n", isHeapEmpty(heap));
	//printf("full : %d\n", isHeapFull(heap));

	element.key = 17;
	insertmaxHeap(heap, element);
	element.key = 61;
	insertmaxHeap(heap, element);
	element.key = 85;
	insertmaxHeap(heap, element);
	element.key = 44;
	insertmaxHeap(heap, element);
	element.key = 33;
	insertmaxHeap(heap, element);
	element.key = 72;
	insertmaxHeap(heap, element);
	element.key = 21;
	insertmaxHeap(heap, element);
	/*element.key = 8;
	insertmaxHeap(heap, element);
	element.key = 9;
	insertmaxHeap(heap, element);
	element.key = 10;
	insertmaxHeap(heap, element);*/
		
	//printf("empty : %d\n", isHeapEmpty(heap));
	//printf("full : %d\n", isHeapFull(heap));
	i = 1;

	deletemaxHeap(heap);
	deletemaxHeap(heap);
	deletemaxHeap(heap);
	/*while (i <= 7)
	{
		printf("i %d : %d\n", i, heap->pNode[i].key);
		i++;
	}*/
	printf("      %d\n", heap->pNode[1].key);
	printf("   %d     %d\n", heap->pNode[2].key, heap->pNode[3].key);
	printf("%d   %d  %d   %d\n", heap->pNode[4].key, heap->pNode[5].key, heap->pNode[6].key, heap->pNode[7].key);
	return (0);
}
