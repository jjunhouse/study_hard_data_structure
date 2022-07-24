#include "linkedstack.h"

int	isLinkedStackEmpty(LinkedStack *pStack)
{
	if (pStack->currentElementCount == 0)
		return (1);
	return (0);
}