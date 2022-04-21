#include "doublylist.h"
#include <stdio.h>

void displayDoublyList(DoublyList* pList)
{
	DoublyListNode* currNode;
	int				length;
	int				i;
	
	if (pList == NULL)
		printf("현재 노드는 비어있습니다!!");
	else
	{
		currNode = pList;
		length = getDoublyListLength(pList);
		printf("총 노드의 수는 %d개 입니다.\n", length);
		i = 0;
		while (currNode != NULL)
		{
			printf("node %d번째 요소는 : %d개 입니다.\n", i, currNode->data);
			i++;
			currNode = currNode->pRLink;
		}
	}
}