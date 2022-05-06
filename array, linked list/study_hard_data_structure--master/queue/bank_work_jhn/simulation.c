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
	newNode->customer.status = arrival; //열거형을 대입함 (현재상태 arrival 상태가됨)
	printSimCustomer(arrivalTime, newNode->customer);

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
    if (currentTime == pArrivalQueue->pFrontNode->customer.arrivalTime)
        insertLQ(pWaitQueue, deleteLQ(pArrivalQueue));
}

QueueNode* processServiceNodeEnd(int currentTime, QueueNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime)
{
	if (NULLCHECK(pServiceNode)
		return (NULL);
	if (pServiceNode->customer.status == start && currentTime == pServiceNode->customer.startTime + pServiceNode->customer.serviceTime)
	{
		pServiceNode->customer.status = end;
		pServiceNode->customer.endTime = currentTime;
		*pServiceUserCount += 1;
		*pTotalWaitTime += pServiceNode->customer.startTime - pServiceNode->customer.arrivalTime;
		printSimCustomer(currentTime, pServiceNode->customer);
	}
}

QueueNode* processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue)
{
	QueueNode *newServiceNode;

	if (NULLCHECK(pWaitQueue))
		return (NULL);
	newServiceNode = calloc(1, sizeof(QueueNode));
	if (NULLCHECK(newServiceNode))
		return (NULL);
	if (pWaitQueue->pFrontNode->customer.arrivalTime <= currentTime)
	{
		pWaitQueue->pFrontNode->customer.startTime = currentTime;
		pWaitQueue->pFrontNode->customer.status = start;
		newServiceNode = deleteLQ(pWaitQueue);
		printSimCustomer(currentTime, pWaitQueue->pFrontNode->customer);
	}
	else
		printf("서비스를 시작하는 손님이 없어용");
	return (newServiceNode);
}

//고객 현재상황 보여주는
void printSimCustomer(int currentTime, SimCustomer customer)
{
	printf("현재시간 : %d\n", currentTime);
	if (coustomer.status == arrival)
		printf("현재 고객 상태 : arrival\n");
	else if (coustomer.status == start)
		printf("현재 고객 상탱 : start\n");
	else 
		printf("현재 고객 상황 : ennd\n");
}

//대기큐 상황 보여주는
void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue)
{
	if (NULLCHECK(pWaitQueue))
		return (NULL)
	printf("현재 시간 : %d \n", currentTime);
	printf("현재 대기인원 : %d \n", pWaitQueue->currentElementCount);
}

// 오늘 온 손님들, 서비스를 받은사람, 평균 대기시간 계산해서 보여주는
void printReport(LinkedQueue *pWaitQueue, int serviceUserCount, int totalWaitTime) 
{
	printf("오늘 온 손놈의 수 : %d \n", pWaitQueue->currentElementCount);
	printf("오늘 서비스 받은 손놈의 수 : %d \n", serviceUserCount);
	printf("오늘 온 손님들의 총대기시간 : %d \n", totalWaitTime);
	printf("오늘 온 손님들의 평균대기시간 : %d \n", totalWaitTime / serviceUserCount);
}