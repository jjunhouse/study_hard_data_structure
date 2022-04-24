#include "circular_linked_list.h"

int	getCircularListLength(CircularList *pList)
{
	if (!pList)
		return (ERROR);
	return (pList->currentElementCount);
}
