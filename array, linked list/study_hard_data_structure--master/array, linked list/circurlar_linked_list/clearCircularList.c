#include "circular_linked_list.h"

void clearCircularList(CircularList* pList)
{
	CircularListNode	*currNode;
	CircularListNode	*nextNode;
	int					i;
	int					listLength;
	
	if (pList == NULL)
		return ;
	listLength = getCircularListLength(pList);
	if (listLength == 0)
		return ;
	currNode = pList->headerNode.pLink;
	nextNode = NULL;
	i = 0;
	while (i < listLength)
	{
		nextNode = currNode->pLink;
		currNode->data = 0;
		currNode->pLink = NULL;
		free(currNode);
		currNode = nextNode;
		i += 1;
	}
	pList->headerNode.pLink = NULL;
	pList->currentElementCount = 0;
}