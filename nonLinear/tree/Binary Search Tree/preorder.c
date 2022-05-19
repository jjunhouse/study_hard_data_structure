#include <stdio.h>
#include "binsearchtree.h"

void	preorder(BSTreeNode	*pRootNode)
{
	if (pRootNode)
	{
		printf("%d \n", pRootNode->data);
		preorder(pRootNode->pLeftChild);
		preorder(pRootNode->pRightChild);
	}
}
