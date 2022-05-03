#include "simulation.h"

SimCustomer	*createCustomer(int arrivalTime, int serviceTime)
{
	SimCustomer	*newCustomer = calloc(1, sizeof(SimCustomer));

	if (!newCustomer)
		return (NULL);
	newCustomer->arrivalTime = arrivalTime;
	newCustomer->serviceTime = serviceTime;
	newCustomer->status = arrival;
	return (newCustomer);
}

QueueNode	*createNode(SimCustomer *customer)
{
	if (!customer)
		return (NULL);

	QueueNode	*newNode = calloc(1, sizeof(QueueNode));
	if (!newNode)
		return (NULL);
	newNode->customerData = customer;
	return (newNode);
}

LinkedQueue	*createQueue()
{
	LinkedQueue	*q = calloc(1, sizeof(LinkedQueue));

	if (!q)
		return (NULL);
	return (q);
}

int	isLinkedQueueEmpty(LinkedQueue *q)
{
	return (q->currentElementCount == 0 ? TRUE : FALSE);
}

// 대기큐의 front를 작업 시작하게 하는 기능 
// 시간이되면 작업이 끝나게 해주는 기능 (free)
// 상태 출력 함수 
// delete 함수 
int	enque(LinkedQueue *q, QueueNode *node)
{
	if (!q || !node)
		return (ERR);
	if (isLinkedQueueEmpty(q))
	{
		q->frontNode = node;
		q->rearNode = node;
	}
	else
	{
		q->rearNode->pLink = node;
		q->rearNode = node;
	}
	q->currentElementCount++;
	return (TRUE);
}

QueueNode	*deque(LinkedQueue *q)
{
	if (!q || isLinkedQueueEmpty(q))
		return (FALSE);
}