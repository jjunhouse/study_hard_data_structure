#include "arraystack.h"
#include <stdio.h>

ArrayStackNode* peekAS(ArrayStack* pStack)
{
    if (!pStack || pStack->currentElementCount == 0)
        return (0);
    return (&pStack->array[pStack->currentElementCount - 1]);
}