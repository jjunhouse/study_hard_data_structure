#include "doublylist.h"

DoublyListNode* getDLElement(DoublyList* pList, int position)
{
	int	listLength;
	int	i;

	DoublyListNode* currNode;
	listLength = getDoublyListLength(pList);
	if ( position < 0 || position > listLength - 1)
		return (NULL);
	else	
	{
		currNode = pList->headerNode.pRLink;
		i = 0;
		while (i < position)
		{
			currNode = currNode->pRLink;
			i++;
		}
		return (currNode);
	}
}
