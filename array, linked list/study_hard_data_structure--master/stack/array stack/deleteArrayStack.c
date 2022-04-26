#include "arraystack.h"

void	deleteArrayStack(ArrayStack *pStack)
{
	if (!pStack)
		return ;
	free(pStack->pElement);
	free(pStack);
}