#include "Arrayqueue.h"

ArrayQueue		*createArrayQueue(int maxElementCount)
{
	ArrayQueue	*q;

	q = calloc(1, sizeof(ArrayQueue));
	if (!q)
		return (NULL);
	q->pElement = calloc(maxElementCount, sizeof(char));
	if (!(q->pElement))
	{
		free(q);
		return (NULL);
	}
	q->maxElementCount = maxElementCount;
	return (q);
}

int 			enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
	if (!pQueue)
		return (ERR);
	if (isArrayQueueFull(pQueue))
		return (FALSE);
	if (pQueue->pElement[pQueue->maxElementCount - 1].data)
		return (FALSE);
	pQueue->pElement[pQueue->currentElementCount].data = element.data;
	pQueue->currentElementCount++;
	pQueue->rear++;
	return (TRUE);
}

ArrayQueueNode	*dequeueAQ(ArrayQueue* pQueue)
{
	ArrayQueueNode	*retNode;

	if (!pQueue)
		return (NULL);
	if (isArrayQueueEmpty(pQueue))
		return (NULL);
	retNode = calloc(1, sizeof(ArrayQueueNode));
	if (!retNode)
		return (NULL);
	retNode->data = pQueue->pElement[pQueue->front].data;
	pQueue->pElement[pQueue->front].data = 0;
	pQueue->front++;
	pQueue->currentElementCount--;
	return (retNode);
}

ArrayQueueNode	*peekAQ(ArrayQueue* pQueue)
{
	if (!pQueue)
		return (NULL);
	return (&pQueue->pElement[pQueue->front]);
}

void			deleteArrayQueue(ArrayQueue* pQueue)
{
	free(pQueue->pElement);
	free(pQueue);
}

void	displayArrayQueue(ArrayQueue *q)
{
	for (int i=q->front; i < q->rear + 1; i++)
	{
		printf("q.data =  %c\n", q->pElement[i].data);
	}
}

int 			isArrayQueueFull(ArrayQueue* pQueue)
{
	return (pQueue->currentElementCount == pQueue->maxElementCount ? TRUE : FALSE);
}

int 			isArrayQueueEmpty(ArrayQueue* pQueue)
{
	return (pQueue->currentElementCount == 0 ? TRUE : FALSE);
}

int	main(void)
{
	ArrayQueue	*q = createArrayQueue(4);

	ArrayQueueNode	node;
	node.data = 'A';
	enqueueAQ(q, node);
	displayArrayQueue(q);
	printf("========================================\n");


	ArrayQueueNode	node1;
	node1.data = 'B';
	enqueueAQ(q, node1);
	displayArrayQueue(q);
	printf("========================================\n");

	ArrayQueueNode	node3;
	node3.data = 'C';
	enqueueAQ(q, node3);
	displayArrayQueue(q);
	printf("========================================\n");

	ArrayQueueNode	node4;
	node4.data = 'D';
	enqueueAQ(q, node4);
	displayArrayQueue(q);
	printf("========================================\n");

	ArrayQueueNode	*front = dequeueAQ(q);
	printf("front.data = %c\n", front->data);
	displayArrayQueue(q);
	printf("========================================\n");

	ArrayQueueNode	*front2 = dequeueAQ(q);
	printf("front2.data = %c\n", front2->data);
	displayArrayQueue(q);
	printf("========================================\n");

	ArrayQueueNode	*front3 = dequeueAQ(q);
	printf("front3.data = %c\n", front3->data);
	displayArrayQueue(q);
	printf("========================================\n");

	ArrayQueueNode	*front4 = dequeueAQ(q);
	printf("front4.data = %c\n", front4->data);
	displayArrayQueue(q);
	printf("========================================\n");

	deleteArrayQueue(q);
	system("leaks a.out > leaks_result; cat leaks_result | \
        grep leaked && rm -rf leaks_result");
	return (0);
}