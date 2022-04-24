#ifndef _ARRAYLIST_
#define _ARRAYLIST_

#include <stdlib.h>

typedef struct ArrayListNodeType
{
	int data;
} ArrayStackNode;

typedef struct ArrayListType
{
	int maxElementCount;		// 최대 원소 개수
	int currentElementCount;	// 현재 원소의 개수
	ArrayStackNode *pElement;	// 원소 저장을 위한 1차원 배열
} ArrayStack;

ArrayStack* createArrayStack(int maxElementCount);
int pushLS(ArrayStack* pStack, ArrayStackNode element);
ArrayStackNode* popLS(ArrayStack* pStack);
ArrayStackNode* peekLS(ArrayStack* pStack);
void deleteArrayStack(ArrayStack* pStack);
int isArrayStackFull(ArrayStack* pStack);
int isArrayStackEmpty(ArrayStack* pStack);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR       -1

#endif
