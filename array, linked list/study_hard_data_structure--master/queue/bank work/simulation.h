#ifndef _SIMULATION_
# define _SIMULATION_

#include <stdio.h>
#include <stdlib.h>

typedef	enum e_flag
{
	TRUE = 1,
	FALSE = 0,
	ERR = -1,
} t_flag;

typedef enum SimStatusType { arrival, start, end } SimStatus;

// 시간 데이터가 담기는데 초기에는 도착시간이랑 서비스시간만 가지고 있음 
// 초기 상태는 arrival인데, start로 바꿔주는 것만 신경쓰면 된다. 
// 작업이 끝나면 end로 
typedef struct SimCustomerType
{
	SimStatus	status;
	int			arrivalTime;
	int			serviceTime;
	int			startTime;
	int			endTime;
} SimCustomer;

// 각 노드는 고객 데이터 가짐
typedef struct QueueNodeType
{
	SimCustomer				*customerData;
	struct QueueNodeType	*pLink;
} QueueNode;

// 큐애 노드들 넣어놓고
typedef struct LinkedQueue
{
	int			currentElementCount;
	QueueNode	*frontNode;
	QueueNode	*rearNode;
} LinkedQueue;

// 함수 프로토타입을 먼저 정의

// create
SimCustomer	*createCustomer(int arrivalTime, int serviceTime);
QueueNode	*createNode(SimCustomer *customer);
LinkedQueue	*createQueue();

// enque
int			enque(LinkedQueue *q, QueueNode *node);
// deque
QueueNode	*deque(LinkedQueue *q);

#endif

