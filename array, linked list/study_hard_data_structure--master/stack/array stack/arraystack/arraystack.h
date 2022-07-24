#ifndef _ARRAY_STACK_
#define _ARRAY_STACK_

#include <stdlib.h>

typedef struct ArrayStackNodeType
{
	char data;
} ArrayStackNode;

typedef struct ArrayStackType
{
    int maxElementCount;
	int currentElementCount;
	ArrayStackNode* array;
} ArrayStack;

ArrayStack* createArrayStack(int size);
int pushAS(ArrayStack* pStack, ArrayStackNode element);
ArrayStackNode* popAS(ArrayStack* pStack);
ArrayStackNode* peekAS(ArrayStack* pStack);
void deleteArrayStack(ArrayStack* pStack);
int isArrayStackFull(ArrayStack* pStack);
int isArrayStackEmpty(ArrayStack* pStack);
void displayArrayStack(ArrayStack *pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR       -1

#endif