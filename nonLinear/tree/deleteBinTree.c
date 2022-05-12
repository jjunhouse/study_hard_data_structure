#include <stdlib.h>
#include "bintree.h"

void		deleteBinTree(BinTree *pBinTree)
{
    deleteBinTreeNode(pBinTree->pRootNode);
    free(pBinTree);
}