#include "doublylist.h"

int	addDLElement(DoublyList *pList, int position, DoublyListNode element)
{
	int		i;
	int		currNodeCount;
	DoublyListNode	*newNode;
	DoublyListNode	*prevNode;
	DoublyListNode	*currNode;

	currNodeCount = pList->currentElementCount;
	if (!pList || position < 0 || position > currNodeCount)
		return (FALSE);
	else
	{
		newNode = malloc(sizeof(DoublyListNode));
		if (!newNode)
			return (FALSE);
		newNode->data = element.data;
		newNode->pLLink = NULL;
		newNode->pRLink = NULL;
		i = 0;
		prevNode = NULL;
		currNode = pList->headerNode.pRLink;
		if (currNodeCount == 0)
		{
			pList->headerNode.pRLink = newNode;
			newNode->pLLink = &pList->headerNode;
		}
		else
		{
			while (i < position)
			{
				prevNode = currNode;
				currNode = currNode->pRLink;
				i += 1;
			}
			if (prevNode == NULL)
			{
				pList->headerNode.pRLink = newNode;
				newNode->pLLink = &pList->headerNode;
			}
			else
			{
				prevNode->pRLink = newNode;
				newNode->pLLink = prevNode;
			}
			newNode->pRLink = currNode;
		}
		pList->currentElementCount += 1;
		return (TRUE);
	}
}
