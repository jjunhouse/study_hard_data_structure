#include "arraystack.h"

ArrayStackNode* popLS(ArrayStack* pStack)
{
   	if (!pStack || isArrayStackEmpty(pStack) == TRUE)
		return (NULL);
	else
    {
        pStack->currentElementCount -= 1;
        return (&(pStack->pElement[pStack->currentElementCount]));
    }

    // if (pStack == NULL)
	// 	return (NULL);
	// if (isArrayStackEmpty(pStack) == TRUE)
	// 	return (NULL);
	// pStack->currentElementCount--;
	// return (&(pStack->pElement[pStack->currentElementCount]));
}