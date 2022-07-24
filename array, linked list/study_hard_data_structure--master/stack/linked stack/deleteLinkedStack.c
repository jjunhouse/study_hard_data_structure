#include "linkedstack.h"

void	deleteLinkedStack(LinkedStack *pStack)
{
	StackNode	*pNode;
	StackNode	*pdelNode;

	pNode = 0;
	pdelNode = 0;
	if (!pStack)
		return ;
	pNode = pStack->pTopElement;
	while (pNode)
	{
		pdelNode = pNode;
		pNode = pNode->pLink;
        pdelNode->pLink = 0;
        pdelNode->data = 0;
        pStack->currentElementCount--;
		free(pdelNode);
    }
	pStack->pTopElement = 0;
	free(pStack);
    pStack = 0;
}