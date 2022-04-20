#include "doublylist.h"

int removeDLElement(DoublyList* pList, int position)
{
	int	i;
	int	currNodeCount;
	DoublyListNode	*prevNode;
	DoublyListNode	*currNode;

	if (!pList)
		return (FALSE);
	currNodeCount = pList->currentElementCount;
	if (position < 0 || position > currNodeCount)
		return (FALSE);
	else
	{
		i = 0;
		prevNode = NULL;
		currNode = pList->headerNode.pRLink;
		while (i < position)
		{
			prevNode = currNode;
			currNode = currNode->pRLink;
			i++;
		}
		if (prevNode == NULL)
		{
			pList->headerNode.pRLink = currNode->pRLink;
			currNode->pRLink->pLLink = &pList->headerNode;

		}
		else if (currNode->pRLink == NULL)
		{
			prevNode->pRLink = currNode->pRLink;
		}
		else
		{
			prevNode->pRLink = currNode->pRLink;
			currNode->pRLink->pLLink = currNode->pLLink; 
		}
		currNode->pRLink = NULL;
		currNode->pLLink = NULL;
		free(currNode);
		pList->currentElementCount -= 1;
		return (TRUE);
	}
}


int	main(void)
{
	DoublyList	*list;
	DoublyListNode	node;
	DoublyListNode	node2;
	DoublyListNode	node3;

	list = createDoublyList();
	node.data = 1;
	node2.data = 2;
	node3.data = 3;
	
	addDLElement(list, 0, node);	// TRUE	맨 앞에 추가(빈 리스트)		[1]
	addDLElement(list, 1, node2);	// TRUE 맨 뒤에 추가			[1, 2]
	addDLElement(list, 1, node3);	// TRUE 중간에 추가			[1, 3, 2]

	removeDLElement(list, 0); 
	removeDLElement(list, 1);

	deleteDoublyList(list);
	system("leaks a.out");
	return (0);
}
