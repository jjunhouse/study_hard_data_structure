#include "linkedQueue.h"


LinkedQueue	*createLinkedQueue()
{
	LinkedQueue	*newQueue = calloc(1, sizeof(LinkedQueue));

	if (NULLCHECK(newQueue))
		return (NULL);
	return (newQueue);
}

int	insertLQ(LinkedQueue* pQueue, QueueNode element)
{
	QueueNode	*newNode;

	if (NULLCHECK(pQueue))
		return (ERR);
	newNode = calloc(1, sizeof(QueueNode));
	if (NULLCHECK(newNode))
		return (ERR);
	newNode->data = element.data;
	if (isLinkedQueueEmpty(pQueue))
	{
		pQueue->pFrontNode = newNode;
		pQueue->pRearNode = newNode;
	}
	else
	{
		pQueue->pRearNode->pRLink = newNode;
		pQueue->pRearNode = newNode;
	}
	pQueue->currentElementCount++;
	return (TRUE);
}

QueueNode	*deleteLQ(LinkedQueue* pQueue)
{
	QueueNode	*delNode;

	if (NULLCHECK(pQueue))
		return (NULL);
	if (isLinkedQueueEmpty(pQueue))
	{
		printf("Queue is now empty\n");
		return (NULL);
	}
	delNode = pQueue->pFrontNode;
	pQueue->pFrontNode = delNode->pRLink;
	return (delNode);
}

QueueNode	*peekFrontLQ(LinkedQueue* pQueue)
{
	return (pQueue->pFrontNode);
}

QueueNode	*peekRearLQ(LinkedQueue* pQueue)
{
	return (pQueue->pRearNode);
}

void 		deleteLinkedQueue(LinkedQueue* pQueue)
{
	QueueNode	*delNode;
	QueueNode	*nextNode;

	if (NULLCHECK(pQueue))
		return ;
	if (isLinkedQueueEmpty(pQueue))
		return ;

	delNode = pQueue->pFrontNode;
	while (delNode && pQueue->currentElementCount--)
	{
		nextNode = delNode->pRLink;
		free(delNode);
		delNode = nextNode;
	}
	free(pQueue);
}

int 		isLinkedQueueEmpty(LinkedQueue* pQueue)
{
	return (pQueue->currentElementCount == 0 ? TRUE : FALSE);
}

void	displayLinkedQueue(LinkedQueue	*q)
{
	QueueNode	*node;
	QueueNode	*nextNode;

	node = q->pFrontNode;
	while (node)
	{
		nextNode = node->pRLink;
		printf("node.data = %c\n", node->data);
		node = nextNode;
	}
}

int	main(void)
{
	LinkedQueue	*lst = createLinkedQueue();

	QueueNode	node1;
	node1.data = 'A';
	insertLQ(lst, node1);
	displayLinkedQueue(lst);
	printf("================================================\n");

	QueueNode	node2;
	node2.data = 'B';
	insertLQ(lst, node2);
	displayLinkedQueue(lst);
	printf("================================================\n");

	QueueNode	node3;
	node3.data = 'C';
	insertLQ(lst, node3);
	displayLinkedQueue(lst);
	printf("================================================\n");

	QueueNode	node4;
	node4.data = 'D';
	insertLQ(lst, node4);
	displayLinkedQueue(lst);
	printf("================================================\n");

	QueueNode	node5;
	node5.data = 'E';
	insertLQ(lst, node5);
	displayLinkedQueue(lst);
	printf("================================================\n");

	printf("now delete!!\n");
	QueueNode	*temp;
	temp = deleteLQ(lst);
	printf("temp's data = %c\n", temp->data);
	free(temp);
	displayLinkedQueue(lst);
	printf("================================================\n");

	temp = deleteLQ(lst);
	printf("temp's data = %c\n", temp->data);
	free(temp);
	displayLinkedQueue(lst);
	printf("================================================\n");

	temp = deleteLQ(lst);
	printf("temp's data = %c\n", temp->data);
	free(temp);
	displayLinkedQueue(lst);
	printf("================================================\n");


	temp = deleteLQ(lst);
	printf("temp's data = %c\n", temp->data);
	free(temp);
	displayLinkedQueue(lst);
	printf("================================================\n");


	temp = deleteLQ(lst);
	printf("temp's data = %c\n", temp->data);
	free(temp);
	displayLinkedQueue(lst);
	printf("================================================\n");

	printf("success!\n");
	deleteLinkedQueue(lst);
	
	system("leaks a.out > leaks_result; cat leaks_result | \
        grep leaked && rm -rf leaks_result");
	return (0);
}