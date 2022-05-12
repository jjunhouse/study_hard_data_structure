#include <stdlib.h>
#include "bintree.h"

void		deleteBinTreeNode(BinTreeNode *pNode)
{
    if (pNode->pLeftChild)
    {
        deleteBinTreeNode(pNode->pLeftChild);
        deleteBinTreeNode(pNode->pRightChild);
        free(pNode);
    }
    if (pNode->pRightChild)
    {
        deleteBinTreeNode(pNode->pLeftChild);
        deleteBinTreeNode(pNode->pRightChild);
        free(pNode);
    }
}