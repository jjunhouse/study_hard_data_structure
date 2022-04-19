#include "linkedlist.h"

void	deleteLinkedList(LinkedList *pList)
{
	ListNode	*currNode;
	ListNode	*nextNode;

	if (pList == NULL)
		return ;
	currNode = pList->headerNode.pLink;
	while (currNode != NULL)
	{
		nextNode = currNode->pLink;
		free(currNode);
		currNode = nextNode;
	}
	free(pList);
}
