#include "circular_linked_list.h"

void	deleteCircularList(CircularList* pList)
{	
	int			i;
	int			length;
	CircularListNode	*curr;
	CircularListNode	*next;
	
	if (pList == NULL)
		return ;
	i = 0;
	length = getCirculatorListLength(pList);
	curr = pList->headerNode.pLink;
	next = NULL;
	pList->headerNode.pLink = NULL;
	while (i < length)
	{
		next = curr->pLink;
		curr->pLink = NULL;
		free(curr);
		curr = next;
		i++;
	}
	free(pList);
}
