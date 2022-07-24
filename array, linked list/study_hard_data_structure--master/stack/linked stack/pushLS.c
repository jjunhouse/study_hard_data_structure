#include "linkedstack.h"

int	pushLS(LinkedStack *pStack, StackNode element)
{
	StackNode	*Node;

	Node = (StackNode *)malloc(sizeof(StackNode));
	if (!Node)
		return(FALSE);
	Node->data = element.data;
	Node->pLink = pStack->pTopElement;
	pStack->pTopElement = Node;
	pStack->currentElementCount++;
	return (TRUE);
}