// getALElement.c
#include "arraylist.h"

ArrayListNode	*getALElement(ArrayList *pList, int position)
{
	int		curr;
	int		max;
	ArrayListNode	*arr;

	curr = pList->currentElementCount;
	max = pList->maxElementCount;
	if (position > max - 1 || position < 0)
		return (NULL);
	else
	{
		arr = pList->pElement;
		return (arr + position);
	}
}
