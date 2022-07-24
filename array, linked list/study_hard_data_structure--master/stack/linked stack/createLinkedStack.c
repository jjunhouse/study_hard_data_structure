#include "linkedstack.h"

LinkedStack	*createLinkedStack(void)
{
	LinkedStack	*stack;

	stack = malloc(sizeof(LinkedStack));
	if (!stack)
		return (0);
	stack->currentElementCount = 0;
	stack->pTopElement = 0;
	return (stack);
}