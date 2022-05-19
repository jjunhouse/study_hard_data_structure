#include <stdlib.h>
#include "binsearchtree.h"

BSTreeNode	*insertChildNodeBST(BSTreeNode *pRootNode, BSTreeNode element)
{
	BSTreeNode	*temp;

	if (!pRootNode)
	{
		temp = malloc(sizeof(BSTreeNode));
		temp->data = element.data;
		temp->pLeftChild = 0;
		temp->pRightChild = 0;
		return (temp);
	}
	if (element.data > pRootNode->data)
		pRootNode->pRightChild = insertChildNodeBST(pRootNode->pRightChild, element);
	else if (element.data < pRootNode->data)
		pRootNode->pLeftChild = insertChildNodeBST(pRootNode->pLeftChild, element);
	return (pRootNode);
}
