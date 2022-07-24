#include <stdio.h>
#include "linkedstack.h"

void	displayPath(LinkedStack *pStack)
{
	StackNode *Node;

	if (!pStack)
		return ;
	Node = pStack->pTopElement;
	while (Node)
	{
		printf("Node Data : %c\n", Node->data);
		Node = Node->pLink;
	}
}
