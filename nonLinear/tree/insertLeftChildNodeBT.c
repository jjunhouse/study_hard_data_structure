#include <stdlib.h>
#include "bintree.h"

BinTreeNode *insertLeftChildNodeBT(BinTreeNode *pParrentNode, BinTreeNode element)
{
    BinTreeNode *node;

    node = malloc(sizeof(BinTreeNode));
    if (!node)
        return (0);
    node->data = element.data;
    node->visited = 0;
    node->pLeftChild = 0;
    node->pRightChild = 0;
    pParrentNode->pLeftChild = node;
    return (node);
}