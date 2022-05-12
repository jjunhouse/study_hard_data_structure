#include <stdlib.h>
#include "bintree.h"

BinTree *makeBinTree(BinTreeNode rootNode)
{
    BinTree *tree;

    tree = malloc(sizeof(BinTree));
    if (!tree)
        return (0);
    tree->pRootNode = &rootNode;
    return (tree);
}