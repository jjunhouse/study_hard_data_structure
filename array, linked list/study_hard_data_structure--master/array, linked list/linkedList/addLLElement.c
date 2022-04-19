#include "linkedlist.h"

int	addLLElement(LinkedList* pList, int position, ListNode element)
{
	int		i;
	int		currentNodeCount;
	ListNode	*newNode;
	ListNode	*prevNode;
	ListNode	*nextNode;
	
	currentNodeCount = pList->currentElementCount;
	if (position < 0 || position > currentNodeCount || !pList)
		return (FALSE);
	else
	{
		newNode = malloc(sizeof(ListNode));
		if (!newNode)
			return (FALSE);
		newNode->data = element.data;
		newNode->pLink = element.pLink;
		if (currentNodeCount == 0)
			pList->headerNode.pLink = newNode;
		else
		{
			i = 0;
			prevNode = NULL;
			nextNode = pList->headerNode.pLink;
			while (i < position)
			{
				prevNode = nextNode;
				nextNode = nextNode->pLink;
				i += 1;
			}
			if (nextNode != NULL)
				newNode->pLink = nextNode;
			if (prevNode != NULL)
				prevNode->pLink = newNode;
		}
		pList->currentElementCount += 1;
		return (TRUE);
	}
}
