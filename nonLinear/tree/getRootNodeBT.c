#include "bintree.h"

BinTreeNode *getRootNodeBT(BinTree *pBinTree)
{
    if (!pBinTree)
        return (0);
    return (pBinTree->pRootNode);
}