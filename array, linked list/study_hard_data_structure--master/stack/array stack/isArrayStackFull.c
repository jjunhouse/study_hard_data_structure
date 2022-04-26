#include "arraystack.h"

int isArrayStackFull(ArrayStack* pStack)
{
	if(!pStack)
		return (ERROR);
    if (pStack->maxElementCount == pStack->currentElementCount)
        return (TRUE);
    return (FALSE);
}
