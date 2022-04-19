#include "linkedlist.h"

ListNode* getLLElement(LinkedList* pList, int position)
{
	int	listLength;
	int	i;
		
	ListNode* currNode;
	listLength  = getLinkedListLength(pList);
	if ( position < 0 || position > listLength - 1)
		return (NULL);
	else
	{
		currNode = pList->headerNode.pLink;	
		i = 0;
		while(i < position)
		{
			currNode = currNode->pLink;
			i++;
		}
		return (currNode);
	}
}
