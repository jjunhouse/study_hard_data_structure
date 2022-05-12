#include "bintree.h"

BinTreeNode	*getRightChildNodeBT(BinTreeNode *pNode)
{
    if (!pNode)
        return (0);
    return (pNode->pRightChild);
}