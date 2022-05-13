#include <stdio.h>
#include "bintree.h"

void    PreorderTraversalBT(BinTreeNode *root)
{
    if (root)
    {
        printf("%c\n", root->data);
        PreorderTraversalBT(root->pLeftChild);
        PreorderTraversalBT(root->pRightChild);
    }
}