#include "linkedQueue.h"
#include "simulation.h"

int main(void)
{
    LinkedQueue     *arrivalQ;
    LinkedQueue     *waitQ;
    QueueNode       *serviceNode;
    int             currTime;
    int             serviceUC;
    int             totalWT;

    arrivalQ = createLinkedQueue();
    waitQ = createLinkedQueue();
    *serviceNode = calloc(1, sizeof(QueueNode));
	if (NULLCHECK(serviceNode))
		return (NULL);

    insertCutomer(0, 3, arrivalQ);
    insertCutomer(2, 1, arrivalQ);
    insertCutomer(4, 1, arrivalQ);
    insertCutomer(6, 2, arrivalQ);
    insertCutomer(8, 3, arrivalQ);

    currTime = 0;
    serviceUC = 0;
    totalWT = 0;

    while (currTime <= 10) // 종료 시간인가...
    {
        printf ("현재시간 %d시 입니다.", currTime);
        processArrival(currTime, arrivalQ, waitQ); // 1번 고객 도착
        
        if (processServiceNodeEnd(currTime, serviceNode, serviceUC, totalWT)->customer->endTime)
        {
            printf("%d번 서비스가 종료되었습니다. ", serviceUC);
            serviceUC += 1;
            if (processServiceNodeStart(currTime, waitQ)
                printf("%d번 서비스가 시작되었습니다. ", serviceUC);
        }    

        printWaitQueueStatus(currTime, waitQ); // 대기 큐 상태 출력
        currTime += 1;
    }
    printf("운영 시간이 종료 되었습니다.");
    printReport(waitQ, 5, ) // 최종 시뮬레이션 결과 출력
}