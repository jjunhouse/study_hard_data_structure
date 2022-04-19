#include "linkedlist.h"

int	getLinkedListLength(LinkedList *pList)
{
	if (pList == NULL)
		return (FALSE);
	else
		return (pList->currentElementCount);
}
