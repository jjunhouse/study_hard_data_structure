#ifndef _HEAP_
#define _HEAP_

typedef struct	minHeapNodeType
{
	int	key;
}	minHeapNode;

typedef struct	minHeapType
{
	int			maxElementCount;
	int			currentElementCount;
	minHeapNode	*pNode;
}	minHeap;

minHeap		*createminHeap(int maxsize);
int			isHeapFull(minHeap *Heap);
int			isHeapEmpty(minHeap *Heap);
int			insertminHeap(minHeap *Heap, minHeapNode element);
minHeapNode	*deleteminHeap(minHeap *Heap);

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE	1
#define FALSE	0

#endif
