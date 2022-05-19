#include "binsearchtree.h"

BSTreeNode	*getRootNodeBST(BSTree *pBSTree)
{
	if (!pBSTree)
		return (0);
	return (pBSTree->pRootNode);
}
