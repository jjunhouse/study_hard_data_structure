#ifndef _CIRCULAR_ARRAY_QUEUE_
#define _CIRCULAR_ARRAY_QUEUE_

#include <stdio.h>
#include <stdlib.h>

typedef	enum e_flag
{
	TRUE = 1,
	FALSE = 0,
	ERR = -1,
} t_flag;

typedef struct ArrayQueueNodeType
{
	char data;
} ArrayQueueNode;

typedef struct ArrayQueueType
{
	int maxElementCount;
	int currentElementCount;
	int front;
	int rear;
	ArrayQueueNode *pElement;
} ArrayQueue;

ArrayQueue		*createArrayQueue(int maxElementCount);

int 			enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element);

ArrayQueueNode	*dequeueAQ(ArrayQueue* pQueue);
ArrayQueueNode	*peekAQ(ArrayQueue* pQueue);

void			deleteArrayQueue(ArrayQueue* pQueue);

int 			isArrayQueueFull(ArrayQueue* pQueue);
int 			isArrayQueueEmpty(ArrayQueue* pQueue);


//additional 
int	NULLCHECK(void *ptr);
#endif
