#include "arraystack.h"

void deleteArrayStack(ArrayStack* pStack)
{
    int i;

    if (!pStack)
        return ;
    i = pStack->currentElementCount;
    while (i--)
    {
        pStack->array[i].data = 0;
        pStack->currentElementCount -= 1;
    }
    free(pStack->array);
    free(pStack);
}