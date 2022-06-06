#include "graphlinkedlist.h"

void	clearLinkedList(LinkedList *pList)
{
	ListNode	*currNode;

	if (pList == NULL)
		return ;
	currNode = pList->headerNode.pLink;
	while (currNode != NULL)
	{
		//currNode->data = 0;
		memset(&(currNode->data), 0, sizeof(currNode->data));
		currNode = currNode->pLink;
	}
	pList->currentElementCount = 0;
}
