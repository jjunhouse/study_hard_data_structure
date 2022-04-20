#include "doublylist.h"

DoublyList	*createDoublyList()
{
	DoublyList	*list;

	list = malloc(sizeof(DoublyList));
	if (!list)
		return (NULL);
	list->currentElementCount = 0;
	list->headerNode.data = 0;
	list->headerNode.pLLink = NULL;
	list->headerNode.pRLink = NULL;
	return (list);
}
