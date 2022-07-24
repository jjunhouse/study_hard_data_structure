#include "arraystack.h"

int pushAS(ArrayStack* pStack, ArrayStackNode element)
{
    if (!pStack || pStack->currentElementCount == pStack->maxElementCount)
        return (FALSE);
    pStack->array[pStack->currentElementCount++].data = element.data;
    return (TRUE);
}