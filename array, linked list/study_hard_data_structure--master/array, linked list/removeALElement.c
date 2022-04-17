// removeALElement.c
#include "arraylist.h"

int removeALElement(ArrayList* pList, int position)
{
	ArrayListNode *array;

	if (position < 0 || pList->currentElementCount == 0 || position > pList->maxElementCount)
		return (FALSE);
	else
	{
		array = pList->pElement;
		for(int i = position; i < pList->currentElementCount - 1; i++)
		{
			*(array + i) = *(array + i + 1);
		}
		pList->currentElementCount -= 1;
		return (TRUE);
	}
}
