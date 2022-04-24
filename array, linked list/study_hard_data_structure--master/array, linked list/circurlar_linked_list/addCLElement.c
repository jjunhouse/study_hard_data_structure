#include "circular_linked_list.h"

int	addCLElement(CircularList *pList, int position, CircularListNode element)
{
	int			i;
	int			listLength;
	CircularListNode	*newNode;
	CircularListNode	*prevNode;
	CircularListNode	*currNode;
	CircularListNode	*tailNode;

	listLength = getCircularListLength(pList);
	if (!pList || position < 0 || position > listLength)
		return (FALSE);
	newNode = (CircularListNode *)malloc(sizeof(CircularListNode));
	if (!newNode)
		return (ERROR);
	newNode->data = element.data;
	newNode->pLink = NULL;
	if (listLength == 0)
	{
		pList->headerNode.pLink = newNode;
		newNode->pLink = newNode;
	}
	else
	{
		i = 0;
		prevNode = NULL;
		currNode = pList->headerNode.pLink;
		tailNode = getTailNode(pList, listLength);
		while (i < position)
		{
			prevNode = currNode;
			currNode = currNode->pLink;
			i += 1;
		}
		if (prevNode == NULL)
		{
			newNode->pLink = currNode;
			pList->headerNode.pLink = newNode;
			tailNode->pLink = newNode;
		}
		else if (i == listLength) // 맨 끝
		{
			newNode->pLink = tailNode->pLink;
			tailNode->pLink = newNode;
		}
		else					// 중간 삽입
		{
			newNode->pLink = currNode;
			prevNode->pLink = newNode;
		}
	}
	pList->currentElementCount += 1;
	return (TRUE);
}
