#include "linkedstack.h"
#include "mapdef.h"

int	pushLS(LinkedStack *pStack, MapPosition element)
{
	StackNode	*node;

	node = (StackNode *)malloc(sizeof(StackNode));
	if (!node)
		return(FALSE);
	node->pos.x = element.x;
	node->pos.y = element.y;
	node->pos.direction = element.direction;
	node->pLink = pStack->pTopElement;
	pStack->pTopElement = node;
	pStack->currentElementCount++;
	return (TRUE);
}