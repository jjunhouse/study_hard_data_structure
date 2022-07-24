#include "linkedstack.h"
#include "mapdef.h"

int	pushLS(LinkedStack *pStack, StackNode element)
{
	StackNode	*node;

	node = (StackNode *)malloc(sizeof(StackNode));
	if (!node)
		return(FALSE);
	node->data = element.data;
	node->pLink = pStack->pTopElement;
	pStack->pTopElement = node;
	pStack->currentElementCount++;
	return (TRUE);
}
