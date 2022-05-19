#include <stdlib.h>
#include "binsearchtree.h"

BSTreeNode	*deleteBSTreeNode(BSTreeNode *pRootNode, int element)
{
	BSTreeNode	*temp;
	
	if (pRootNode == NULL)
		return (pRootNode);
	if (element < pRootNode->data)
		pRootNode->pLeftChild = deleteBSTreeNode(pRootNode->pLeftChild, element);
	else if (element > pRootNode->data)
		pRootNode->pRightChild = deleteBSTreeNode(pRootNode->pRightChild, element);
	else
	{
		if (pRootNode->pLeftChild == NULL)
		{
			temp = pRootNode->pRightChild;
			free(pRootNode);
			return (temp);
		}
		else if (pRootNode->pRightChild == NULL)
		{
			temp = pRootNode->pLeftChild;
			free(pRootNode);
			return (temp);
		}
		temp = searchminValueNode(pRootNode->pRightChild);
		pRootNode->data = temp->data;
		pRootNode->pRightChild = deleteBSTreeNode(pRootNode->pRightChild, temp->data);
	}
	return (pRootNode);
}
