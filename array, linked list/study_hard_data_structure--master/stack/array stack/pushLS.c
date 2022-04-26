#include "arraystack.h"

int pushLS(ArrayStack* pStack, ArrayStackNode element)
{
    if (!pStack || isArrayStackFull(pStack) == TRUE)
		return (ERROR);
	else
    {
        pStack->currentElementCount += 1;
        pStack->pElement[pStack->currentElementCount - 1] = element;
        return (TRUE);
    }

    // if (pStack == NULL)
	// 	return (ERROR);
	// if (isArrayStackFull(pStack) == TRUE)
	// 	return (FALSE);
	// pStack->pElement[pStack->currentElementCount] = element;
	// pStack->currentElementCount++;
	// return (TRUE);
}
