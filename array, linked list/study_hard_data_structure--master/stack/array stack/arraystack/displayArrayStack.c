#include "arraystack.h"
#include <stdio.h>

void displayArrayStack(ArrayStack *pStack)
{
    int i;

    if (!pStack)
        return ;
    if (isArrayStackEmpty(pStack))
    {
        printf("빈 스택입니다.\n");
        return ;
    }
    i = pStack->currentElementCount;
    while (i--)
    {
        printf("Stack Data : %c\n", pStack->array[i].data);
    }
}