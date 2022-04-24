#include "circular_linked_list.h"

CircularListNode	*getTailNode(CircularList *pList, int listLength)
{
	int			i;
	CircularListNode	*currNode;

	i = 0;
	currNode = pList->headerNode.pLink;
	while (i + 1 < listLength)
	{
		currNode = currNode->pLink;
		i += 1;
	}
	return (currNode);
}
