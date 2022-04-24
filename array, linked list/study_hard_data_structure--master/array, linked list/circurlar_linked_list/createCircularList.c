#include "circular_linked_list.h"

CircularList	*createCircularList()
{
	CircularList	*list;

	list = (CircularList *)malloc(sizeof(CircularList));
	if (!list)
		return (NULL);
	list->currentElementCount = 0;
	list->headerNode.data = 0;
	list->headerNode.pLink = NULL;
	return (list);
}
