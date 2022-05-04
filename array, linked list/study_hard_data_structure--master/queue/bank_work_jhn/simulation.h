#ifndef _SIMULATION_
# define _SIMULATION_

#include <stdio.h>
#include <stdlib.h>

typedef enum SimStatusType { arrival, start, end } SimStatus;

typedef struct SimCustomerType
{
    SimStatus status;
    int arrivalTime;// 도착 시각.
    int serviceTime;// 서비스 시간.
    int startTime;// 시작 시각.
    int endTime;// 종료 시각: 시작 시각 + 서비스 시간.
} SimCustomer;

void insertCutomer(int arrivalTime, int processTime, LinkedQueue *pQueue); //도착큐에 고객생성
void processArrival(int currentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue); // 도착큐에서 대기큐로 디큐 앤 인큐
QueueNode* processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue); //대기큐에서 받아서 서비스큐 디큐 하는 
QueueNode* processServiceNodeEnd(int currentTime, QueueNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime); // 
void printSimCustomer(int currentTime, SimCustomer customer); //고객 현재상황 보여주는 
void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue); //대기큐 상황 보여주는
void printReport(LinkedQueue *pWaitQueue, int serviceUserCount, int totalWaitTime); // 오늘 온 손님들, 서비스를 받은사람, 평균 대기시간 계산해서 보여주는



#endif