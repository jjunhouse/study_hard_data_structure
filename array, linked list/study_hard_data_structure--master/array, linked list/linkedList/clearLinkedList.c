#include "linkedlist.h"

void	clearLinkedList(LinkedList *pList)
{
	ListNode	*currNode;

	if (pList == NULL)
		return ;
	currNode = pList->headerNode.pLink;
	while (currNode != NULL)
	{
		currNode->data = 0;
		currNode = currNode->pLink;
	}
	pList->currentElementCount = 0;
}
