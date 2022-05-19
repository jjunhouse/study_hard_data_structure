#include "binsearchtree.h"

BSTreeNode	*searchminValueNode(BSTreeNode *pRootNode)
{
	BSTreeNode	*Node;

	Node = pRootNode;
	while (Node && Node->pLeftChild != 0)
		Node = Node->pLeftChild;
	return (Node);
}
