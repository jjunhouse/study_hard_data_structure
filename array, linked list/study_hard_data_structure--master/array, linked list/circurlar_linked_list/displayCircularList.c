#include "circular_linked_list.h"
#include "stdio.h"

void displayCircularList(CircularList* pList)
{
	CircularListNode*	currNode;
	int					listlength;
	int					i;

	if (pList == NULL)
		printf("현재 리스트는 비어 있사옵니다!\n")
	else
	{
		currNode = pList->headerNode.pLink;
		listLength = getCircularListLength(pList);
		i = 0;
		while (i < listLength)
		{
			printf("%d번째 node의 데이터는 %d 입니다.\n", i, currNode->data);
			currNode = currNode->pLink;
			i++;
		}
	}
}