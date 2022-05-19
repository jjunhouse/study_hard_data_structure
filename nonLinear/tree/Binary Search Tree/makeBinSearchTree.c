#include <stdlib.h>
#include "binsearchtree.h"

BSTree	*makeBinSearchTree(BSTreeNode rootNode)
{
	BSTree	*tree;

	tree = (BSTree *)malloc(sizeof(BSTree));
	if (!tree)
		return (0);
	tree->pRootNode = &rootNode;
	return (tree);
}
