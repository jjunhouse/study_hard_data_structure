#include "arraystack.h"

ArrayStack  *createArrayStack(int size)
{
    ArrayStack      *stack;

    stack = (ArrayStack *)malloc(sizeof(ArrayStack));
    if (!stack)
        return (0);
    stack->maxElementCount = size;
    stack->currentElementCount = 0;
    stack->array = (ArrayStackNode *)malloc(sizeof(ArrayStackNode) * size);
    if (!stack->array)
        return (0);
    return (stack);
}