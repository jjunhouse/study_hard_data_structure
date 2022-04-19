#include "linkedlist.h"

LinkedList	*createLinkedList()
{
	LinkedList	*list;

	list = malloc(sizeof(LinkedList));
	if (!list)
		return (NULL);
	list->currentElementCount = 0;
	return (list);
}
