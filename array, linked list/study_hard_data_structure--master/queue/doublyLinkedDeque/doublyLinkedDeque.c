#include "doublyLinkedDeque.h"

LinkedDeque* createLinkedDeque()
{
	LinkedDeque	*newLQ;

	newLQ = calloc(1, sizeof(LinkedDeque));
	if (NULLCHECK(newLQ))
		return (NULL);
	return (newLQ);
}

int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode	*newNode;

	if (NULLCHECK(pDeque))
		return (ERR);
	newNode = calloc(1, sizeof(DequeNode));
	if (NULLCHECK(newNode))
		return (ERR);
	newNode->data = element.data;
	if (isLinkedDequeEmpty(pDeque))
	{
		pDeque->pFrontNode = newNode;
		pDeque->pRearNode = newNode;
	}
	else
	{
		newNode->pRLink = pDeque->pFrontNode;
		pDeque->pFrontNode->pLLink = newNode;
		pDeque->pFrontNode = newNode;
	}
	pDeque->currentElementCount++;
	return (TRUE);
}

int 		insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode	*newNode;

	if (NULLCHECK(pDeque))
		return (ERR);
	newNode = calloc(1, sizeof(DequeNode));
	if (NULLCHECK(newNode))
		return (ERR);
	newNode->data = element.data;
	if (isLinkedDequeEmpty(pDeque))
	{
		pDeque->pFrontNode = newNode;
		pDeque->pRearNode = newNode;
	}
	else
	{
		newNode->pLLink = pDeque->pRearNode;
		pDeque->pRearNode->pRLink = newNode;
		pDeque->pRearNode = newNode;
	}
	pDeque->currentElementCount++;
	return (TRUE);
}

DequeNode	*deleteFrontLD(LinkedDeque* pDeque)
{
	DequeNode	*delNode;

	if (NULLCHECK(pDeque))
		return (NULL);
	if (isLinkedDequeEmpty(pDeque))
	{
		printf("Deque is now empty\n");
		return (NULL);
	}
	delNode = pDeque->pFrontNode;
	pDeque->pFrontNode = delNode->pRLink;
	pDeque->pFrontNode->pLLink = NULL;
	return (delNode);
}

DequeNode	*deleteRearLD(LinkedDeque* pDeque)
{
	DequeNode	*delNode;

	if (NULLCHECK(pDeque))
		return (NULL);
	if (isLinkedDequeEmpty(pDeque))
	{
		printf("Deque is now empty\n");
		return (NULL);
	}
	delNode = pDeque->pRearNode;
	pDeque->pRearNode = delNode->pLLink;
	pDeque->pRearNode->pRLink = NULL;
	return (delNode);
}
DequeNode	*peekFrontLD(LinkedDeque* pDeque)
{
	DequeNode	*retNode;

	if (NULLCHECK(pDeque))
		return (NULL);
	if (isLinkedDequeEmpty(pDeque))
	{
		printf("Deque is now empty\n");
		return (NULL);
	}
	return (pDeque->pFrontNode);
}

DequeNode	*peekRearLD(LinkedDeque* pDeque)
{
	DequeNode	*retNode;

	if (NULLCHECK(pDeque))
		return (NULL);
	if (isLinkedDequeEmpty(pDeque))
	{
		printf("Deque is now empty\n");
		return (NULL);
	}
	return (pDeque->pRearNode);
}

void 		deleteLinkedDeque(LinkedDeque* pDeque)
{
	DequeNode	*frontNode;
	DequeNode	*nextNode;

	if (NULLCHECK(pDeque))
		return ;
	frontNode = pDeque->pFrontNode;
	while (frontNode)
	{
		nextNode = frontNode->pRLink;
		free(frontNode);
		frontNode = nextNode;
	}
	free(pDeque);
}

void	displayLinkedDeque(LinkedDeque	*pDeque)
{
	DequeNode	*frontNode;

	if (NULLCHECK(pDeque))
		return ;
	frontNode = pDeque->pFrontNode;
	while (frontNode)
	{
		printf("Node->data = %c\n", frontNode->data);
		frontNode = frontNode->pRLink;
	}
}
int 		isLinkedDequeEmpty(LinkedDeque* pDeque)
{
	if (NULLCHECK(pDeque))
		return (ERR);
	return (pDeque->currentElementCount == 0 ? TRUE : FALSE);
}

int	main(void)
{
	LinkedDeque	*lst = createLinkedDeque();

	DequeNode	node1;
	node1.data = 'A';
	insertFrontLD(lst, node1);

	displayLinkedDeque(lst);
	printf("================================================\n");
	DequeNode	node2;
	node2.data = 'B';
	insertRearLD(lst, node2);

	displayLinkedDeque(lst);
	printf("================================================\n");
	DequeNode	node3;
	node3.data = 'C';
	insertFrontLD(lst, node3);

	displayLinkedDeque(lst);
	printf("================================================\n");
	DequeNode	node4;
	node4.data = 'D';
	insertRearLD(lst, node4);
	displayLinkedDeque(lst);
	printf("================================================\n");
	DequeNode	node5;
	node5.data = 'E';
	insertRearLD(lst, node5);
	displayLinkedDeque(lst);
	printf("================================================\n");

	deleteRearLD(lst);
	displayLinkedDeque(lst);
	printf("================================================\n");

	deleteRearLD(lst);
	displayLinkedDeque(lst);
	printf("================================================\n");

	deleteFrontLD(lst);
	displayLinkedDeque(lst);
	printf("================================================\n");


	deleteLinkedDeque(lst);
	return (0);
}