#include "linkedstack.h"

StackNode	*peekLS(LinkedStack *pStack)
{
	StackNode	*peekNode;

	peekNode = 0;
	if (isLinkedStackEmpty(pStack))
		return (peekNode);
	peekNode = pStack->pTopElement;
	return (peekNode);
}