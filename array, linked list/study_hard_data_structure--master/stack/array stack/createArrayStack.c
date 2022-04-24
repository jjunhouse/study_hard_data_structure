#include "arraystack.h"

ArrayStack* createArrayStack(int maxElementCount)
{
    ArrayStack *stack;
    ArrayStackNode *node;

    stack = malloc(sizeof(ArrayStack));
    if (!stack)
        return (0);
    node = malloc(sizeof(ArrayStackNode) * maxElementCount);
    if (!node)
        return (0);
    stack->maxElementCount = maxElementCount;
    stack->currentElementCount = 0;
    stack->pElement = node;
    if (!stack->pElement)
        return (NULL);
    return (stack);
}
