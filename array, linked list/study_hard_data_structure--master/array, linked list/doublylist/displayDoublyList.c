#include "doublylist.h"
#include <stdio.h>

void displayDoublyList(DoublyList* pList)
{
	DoublyListNode* currNode;
	int				Length;
	int				i;
	
	if (pList == NULL)
		printf("현재 노드는 비어있습니다?");
	else
	{
		currNode = pList;
		Length = getDoublyListLength(pList);
		printf("총 노드의 수는 %d개 입니다.", Length);
		while (!pList)
		{
			printf("node %d번째 요소는 : %d개 입니다.", i, currNode->currentElementCount);
			i++;
			currNode = currNode->pRLink;
		}
	}
}