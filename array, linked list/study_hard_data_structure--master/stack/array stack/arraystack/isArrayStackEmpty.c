#include "arraystack.h"

int isArrayStackEmpty(ArrayStack* pStack)
{
    if (!pStack)
        return (ERROR);
    if (pStack->currentElementCount == 0)
        return (TRUE);
    return (FALSE);
}