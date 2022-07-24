#include "arraystack.h"

int isArrayStackFull(ArrayStack* pStack)
{
    if (!pStack)
        return (ERROR);
    if (pStack->currentElementCount == pStack->maxElementCount)
        return (TRUE);
    return (FALSE);
}