#ifndef _HEAP_
#define _HEAP_

typedef struct	maxHeapNodeType
{
	int	key;
}	maxHeapNode;

typedef struct	maxHeapType
{
	int			maxElementCount;
	int			currentElementCount;
	maxHeapNode	*pNode;
}	maxHeap;

maxHeap		*createmaxHeap(int maxsize);
int			isHeapFull(maxHeap *Heap);
int			isHeapEmpty(maxHeap *Heap);
int			insertmaxHeap(maxHeap *Heap, maxHeapNode element);
maxHeapNode	*deletemaxHeap(maxHeap *Heap);

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE	1
#define FALSE	0

#endif
