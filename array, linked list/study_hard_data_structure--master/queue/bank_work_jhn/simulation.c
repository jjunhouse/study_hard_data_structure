#include "simulation.h"
#include "linkedQueue.h" 

 //도착큐에 고객생성
void insertCustomer(int arrivalTime, int processTime, LinkedQueue *pQueue)
{
    QueueNode   *newNode;
    
    if (NULLCHECK(pQueue))
		return (ERR);
	newNode = calloc(1, sizeof(QueueNode));
	if (NULLCHECK(newNode))
		return (ERR);
    newNode->customer.arrivalTime = arrivalTime;
    newNode->customer.serviceTime = processTime;
    
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
    pQueue->currentElementCount += 1;
}

 // 도착큐에서 대기큐로 디큐 앤 인큐
void processArrival(int currentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue)
{
    if (currentTime == pArrivalQueue->pFrontNode->arrivalTime)
        insertLQ(pWaitQueue, deleteLQ(pArrivalQueue));
}

