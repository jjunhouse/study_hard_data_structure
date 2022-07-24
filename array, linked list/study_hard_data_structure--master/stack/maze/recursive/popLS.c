#include "linkedstack.h"

StackNode	*popLS(LinkedStack *pStack)
{
	StackNode	*popNode;

	popNode = 0;
	if (isLinkedStackEmpty(pStack))
		return (popNode);
	popNode = pStack->pTopElement;
	pStack->pTopElement = popNode->pLink;
	popNode->pLink = 0;
	pStack->currentElementCount--;
	return (popNode);
}