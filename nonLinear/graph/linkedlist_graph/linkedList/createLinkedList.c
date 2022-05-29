#include "graphlinkedlist.h"

LinkedList	*createLinkedList()
{
	LinkedList	*list;

	list = calloc(1, sizeof(LinkedList));
	if (!list)
		return (NULL);
	list->currentElementCount = 0;
	return (list);
}
