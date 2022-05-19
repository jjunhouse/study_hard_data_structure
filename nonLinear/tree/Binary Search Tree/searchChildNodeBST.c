#include "binsearchtree.h"

#include "binsearchtree.h"

BSTreeNode	*searchChildNodeBSTrec(BSTreeNode *pRootNode, BSTreeNode element)
{
	if (!pRootNode)
		return (pRootNode);
	if (element.data == pRootNode->data)
		return (pRootNode);
	if (element.data < pRootNode->data)
		return (searchChildNodeBSTrec(pRootNode->pLeftChild, element));
	if (element.data > pRootNode->data)
		return (searchChildNodeBSTrec(pRootNode->pRightChild, element));
	return (pRootNode);
}

BSTreeNode	*searchChildNodeBSTite(BSTree *pBSTree, BSTreeNode element)
{
	BSTreeNode	*searchNode;

	searchNode = pBSTree->pRootNode;
	while (pBSTree)
	{
		if (element.data == searchNode->data)
			return (searchNode);
		if (element.data < searchNode->data)
			searchNode = searchNode->pLeftChild;
		else
			searchNode = searchNode->pRightChild;
	}
	return (0);
}
