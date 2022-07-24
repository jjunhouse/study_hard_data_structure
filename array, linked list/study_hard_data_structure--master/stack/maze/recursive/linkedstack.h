#ifndef _LINKED_STACK_
#define _LINKED_STACK_
#include "mapdef.h"
#include <stdlib.h>

typedef struct StackNodeType
{
	MapPosition	pos;
	// 여기 값 어떻게 넣죠 {0, 0} 부터 시작해서 position[0] = x 좌표 , position[1] = y 좌표 이렇게 활용하는 건 어떨까요..? 
	// DIRECTION_OFFSETS 은 상우하좌 로 이동할 때만 사용하는 값인 것 같습니당
	struct	StackNodeType* pLink;
} StackNode;

// 궁금한게 있어요 NUM_DIRECTIONS << 이거 왜 값이 4인가요
// 상하좌우 4방향으로 탐색하기 위해서 사용한 것 같아요. 만약 8방향(대각선 포함)이면 8로 바꿀 수 있을 것 같아요!
// 근데 저희 0, -1, 1아 맞네요
// DIRECTION_OFFSETS[NUM_DIRECTIONS][2] 근데 왜 뒤에는 2인가요...
// 0번 인덱스는 x, 1번 인덱스는 y값으로 쓰는 것 같습니당. 
// DIRECTION_OFFSETS[0] = {0, -1} 이니까 y 에서 -1 을 이동하는거면 위로 이동하는거니까 ㅇ...음..네..!아닙니다 .. 저도 제대로 이해하고 있는게 맞는지 확신이 없습니다 흑
// 아 이해했습니다 ㅋㅋㅋㅋㅋㅋ 죄송합니다
typedef struct LinkedStackType
{
	int currentElementCount;
	StackNode* pTopElement;
} LinkedStack;

LinkedStack* createLinkedStack();
int pushLS(LinkedStack* pStack, MapPosition element);
StackNode* popLS(LinkedStack* pStack);
StackNode* peekLS(LinkedStack* pStack);
void deleteLinkedStack(LinkedStack* pStack);
int isLinkedStackEmpty(LinkedStack* pStack);
void displayStack(LinkedStack *pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0

#endif