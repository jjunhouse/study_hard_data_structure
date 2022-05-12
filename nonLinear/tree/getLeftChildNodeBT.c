#include "bintree.h"

BinTreeNode	*getLeftChildNodeBT(BinTreeNode *pNode)
{
    if (!pNode)
        return (0);
    return (pNode->pLeftChild);
}