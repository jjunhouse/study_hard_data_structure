#include "arraystack.h"

ArrayStackNode* peekLS(ArrayStack* pStack)
{
	ArrayStackNode	*arr;

    arr = pStack->pElement;
	if (!pStack || pStack->pElement == NULL)
		return (NULL);
	else
		return (arr + pStack->currentElementCount);
}