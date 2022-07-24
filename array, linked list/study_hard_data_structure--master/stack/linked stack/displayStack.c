#include "linkedstack.h"
#include <stdio.h>

void	displayStack(LinkedStack *pStack)
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