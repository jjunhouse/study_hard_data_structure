#include "linkedlist.h"

int	removeLLElement(LinkedList *pList, int position)
{
	int			i;
	int			currNodeCount;
	ListNode	*prevNode;
	ListNode	*currNode;
	
	currNodeCount = pList->currentElementCount;
	if (!pList || position < 0 || position > currNodeCount - 1)
		return (FALSE);
	else
	{
		i = 0;
		prevNode = NULL;
		currNode = pList->headerNode.pLink;
		while (currNode != NULL && i < position)
		{
			prevNode = currNode;
			currNode = currNode->pLink;
			i += 1;
		}
		if (prevNode == NULL)
			pList->headerNode.pLink = currNode->pLink;
		else
		{
			prevNode->pLink = currNode->pLink;
			currNode->pLink = NULL;
		}
		free(currNode);
		pList->currentElementCount -= 1;
		return (TRUE);
	}
}
