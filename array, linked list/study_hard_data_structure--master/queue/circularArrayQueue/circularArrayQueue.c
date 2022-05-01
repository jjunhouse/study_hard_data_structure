#include "circularArrayQueue.h"

ArrayQueue	*createArrayQueue(int maxElementCount)
{
	ArrayQueue	*newAQ;

	newAQ = calloc(1, sizeof(ArrayQueue));
	if (NULLCHECK(newAQ))
		return (NULL);
	newAQ->pElement = calloc(maxElementCount, sizeof(ArrayQueueNode));
	if (NULLCHECK(newAQ->pElement))
	{
		free(newAQ);
		return (NULL);
	}
	newAQ->maxElementCount = maxElementCount;
	return (newAQ);
}

int isArrayQueueEmpty(ArrayQueue* pQueue)
{
	if (NULLCHECK(pQueue))
		return (ERR);
	return (pQueue->currentElementCount == 0 ? TRUE : FALSE);
}

int isArrayQueueFull(ArrayQueue* pQueue)
{
	return (pQueue->currentElementCount == pQueue->maxElementCount ? TRUE : FALSE);
}

// 원소 추가 가능 여부 판단해서 가능하면 추가하고, rear와 count 증가
int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
	int	idx;

	if (NULLCHECK(pQueue))
		return (ERR);
	else if (isArrayQueueFull(pQueue))
	{
		printf("ArrayQueue is Full Now.\n");
		return (FALSE);
	}
	if (isArrayQueueEmpty(pQueue))
		idx = 0;
	else
		idx = pQueue->rear + 1 % pQueue->maxElementCount;
	pQueue->pElement[idx] = element;
	pQueue->rear = idx;
	pQueue->currentElementCount++;
	return (TRUE);
}

ArrayQueueNode	*peekAQ(ArrayQueue* pQueue)
{
	if (NULLCHECK(pQueue))
		return (NULL);
	if (isArrayQueueEmpty(pQueue))
	{
		printf("ArrayQueue is Empty Now.\n");
		return (NULL);
	}
	if (pQueue->rear > pQueue->maxElementCount)
		return (&(pQueue->pElement[pQueue->front % pQueue->maxElementCount]));
	return (&(pQueue->pElement[0]));
}

ArrayQueueNode	*dequeueAQ(ArrayQueue* pQueue)
{
	ArrayQueueNode	*retNode;

	if (NULLCHECK(pQueue))
		return (NULL);
	if (isArrayQueueEmpty(pQueue))
	{
		printf("ArrayQueue is Empty Now.\n");
		return (NULL);
	}
	retNode = calloc(1, sizeof(ArrayQueueNode));
	retNode->data = pQueue->pElement[pQueue->front % pQueue->maxElementCount].data;
	pQueue->pElement[pQueue->front % pQueue->maxElementCount].data = 0;
	pQueue->front++;
	pQueue->currentElementCount--;
	return (retNode);
}

void	deleteArrayQueue(ArrayQueue	*pQueue)
{
	if (NULLCHECK(pQueue))
		return ;
	free(pQueue->pElement);
	free(pQueue);
}

void	displayArrayQueue(ArrayQueue *pQueue)
{
	if (NULLCHECK(pQueue))
		return ;
	for (int i= pQueue->front % pQueue->maxElementCount; i < pQueue->rear + 1 % pQueue->maxElementCount; i++)
	{
		printf("pQueue[%d] = %c\n", i, pQueue->pElement[i].data);
	}
	return ;
}

int	main(void)
{
	ArrayQueue	*q = createArrayQueue(4);

	ArrayQueueNode	node1;
	node1.data = 'A';
	enqueueAQ(q, node1);

	ArrayQueueNode	node2;
	node2.data = 'B';
	enqueueAQ(q, node2);

	ArrayQueueNode	node3;
	node3.data = 'C';
	enqueueAQ(q, node3);

	ArrayQueueNode	node4;
	node4.data = 'D';
	enqueueAQ(q, node4);

	printf("display!\n");
	displayArrayQueue(q);
	printf("==============================================\n");

	printf("peek!\n");
	ArrayQueueNode	*rear = peekAQ(q);
	printf("now front is %c\n", rear->data);
	printf("==============================================\n");

	printf("deque!\n");
	ArrayQueueNode	*front = dequeueAQ(q);
	free(front);
	printf("now deque return data : %c\n", front->data);
	printf("==============================================\n");

	printf("display!\n");
	displayArrayQueue(q);
	printf("==============================================\n");

	printf("try enque!\n");
	ArrayQueueNode	node5;
	node5.data = 'E';
	enqueueAQ(q, node5);
	printf("==============================================\n");

	printf("display!\n");
	displayArrayQueue(q);
	printf("==============================================\n");

	printf("deque!\n");
	front = dequeueAQ(q);
	printf("now deque return data : %c\n", front->data);
	free(front);
	printf("==============================================\n");

	printf("display!\n");
	displayArrayQueue(q);
	printf("==============================================\n");


	deleteArrayQueue(q);
	system("leaks a.out > leaks_result; cat leaks_result | \
        grep leaked && rm -rf leaks_result");
	return (0);
}