#include "arraystack.h"

int isArrayListFull(ArrayStack* pStack)
{
	if(!pStack)
		return (ERROR);
    if (pStack->maxElementCount == pStack->currentElementCount)
        return (TRUE);
    return (FALSE);
}
